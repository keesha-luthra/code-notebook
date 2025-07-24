class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < m; i++){
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        for(int j = 0; j < m; j++){
            dp[m - 1][j] = triangle[m - 1][j];
        }
        for(int i = m - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, dg);
            }
        }
        return dp[0][0];
    }
};