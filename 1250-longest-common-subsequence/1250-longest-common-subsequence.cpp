class Solution {
// private:
// int helper(int index1, int index2, string text1, string text2, vector<vector<int>>& dp){
//     if(index1 < 0 || index2 < 0) return 0;
//     if(dp[index1][index2] != -1) return dp[index1][index2];
//     if(text1[index1] == text2[index2]){
//         dp[index1][index2] = 1 + helper(index1 - 1, index2 - 1, text1, text2, dp);
//     }
//     else{
//     dp[index1][index2] = 0 + max(helper(index1 - 1, index2, text1, text2, dp), helper(index1, index2 - 1, text1, text2, dp));
//     }
//     return dp[index1][index2];
// }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int index1 = text1.size();
        int index2 = text2.size();
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));
        // return helper(index1 - 1, index2 - 1, text1, text2, dp);
        for(int i = 0; i < index1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < index2; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= index1; i++){
            for(int j = 1; j <= index2; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
        }
    }
    return dp[index1][index2];
    }
};