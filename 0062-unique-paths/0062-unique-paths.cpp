class Solution {
// private:
// int helper(int i, int j, vector<vector<int>> &dp){
//     if(i == 0 && j == 0) return 1;
//     if(i < 0 || j < 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int up = helper(i - 1, j, dp);
//     int left = helper(i, j - 1, dp);
//     dp[i][j] = up + left;
//     return dp[i][j];
// }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return helper(m - 1, n - 1, dp);
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = 0;
                int left = 0;
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};