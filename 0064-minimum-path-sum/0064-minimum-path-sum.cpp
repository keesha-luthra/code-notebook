class Solution {
// int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
//     if(i == 0 && j == 0) return grid[i][j];
//     // return such a big value that this path can never become minimum
//     if(i < 0 || j < 0) return INT_MAX;
//     if(dp[i][j] != -1) return dp[i][j];
//     int upReturnValue = helper(i - 1, j, grid, dp);
//     int leftReturnValue = helper(i, j - 1, grid, dp);
//     int up = INT_MAX;
//     int left = INT_MAX;

//     if(upReturnValue != INT_MAX) up = grid[i][j] + upReturnValue;
//     if(leftReturnValue != INT_MAX) left = grid[i][j] + leftReturnValue;
//     dp[i][j] = min(up, left); 
//     return dp[i][j];
// }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return helper(m - 1, n - 1, grid, dp);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = INT_MAX;
                int left = INT_MAX;
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    if(i > 0) up = grid[i][j] + dp[i - 1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};