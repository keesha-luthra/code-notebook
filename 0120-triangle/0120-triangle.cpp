class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j, int m){
        if(i == m - 1) return triangle[m - 1][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int d = triangle[i][j] + helper(triangle, dp, i + 1, j, m);
        int dg = triangle[i][j] + helper(triangle, dp, i + 1, j + 1, m);
        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m, vector<int>(m, INT_MAX));
        return helper(triangle, dp, 0, 0, m);
    }
};