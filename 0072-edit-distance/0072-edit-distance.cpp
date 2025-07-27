class Solution {
// private:
// int helper(int i, int j, string word1, string word2, vector<vector<int>>& dp){
//     if(i == 0) return j;
//     if(j == 0) return i;
//     if(dp[i][j] != -1) return dp[i][j];
//     int insert = 0;
//     int del = 0;
//     int replace = 0;
//     if(word1[i - 1] == word2[j - 1]) dp[i][j] = helper(i - 1, j - 1, word1, word2, dp);
//     else{
//         insert = 1 + helper(i, j - 1, word1, word2, dp);
//         del = 1 + helper(i - 1, j, word1, word2, dp);
//         replace = 1 + helper(i - 1, j - 1, word1, word2, dp);
//         dp[i][j] = min(insert, min(del, replace));
//     }
//     return dp[i][j];
// }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int insert = 0;
        int del = 0;
        int replace = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        // return helper(n, m, word1, word2, dp);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j- 1];
                else{
                    insert = 1 + dp[i][j - 1];
                    del = 1 + dp[i - 1][j];
                    replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m];
    }
};