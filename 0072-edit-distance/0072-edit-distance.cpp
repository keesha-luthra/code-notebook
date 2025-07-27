class Solution {
private:
int helper(int i, int j, string word1, string word2, vector<vector<int>>& dp){
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];
    int insert = 0;
    int del = 0;
    int replace = 0;
    if(word1[i - 1] == word2[j - 1]) dp[i][j] = helper(i - 1, j - 1, word1, word2, dp);
    else{
        insert = 1 + helper(i, j - 1, word1, word2, dp);
        del = 1 + helper(i - 1, j, word1, word2, dp);
        replace = 1 + helper(i - 1, j - 1, word1, word2, dp);
        dp[i][j] = min(insert, min(del, replace));
    }
    return dp[i][j];
}
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, word1, word2, dp);
    }
};