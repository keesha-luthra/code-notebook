class Solution {
public:
    // int helper(int ind, vector<int>& dp){
    //     if(ind <= 1) return 1;
    //     if(dp[ind] != -1) return dp[ind];
    //     else return dp[ind] = helper(ind - 1, dp) + helper(ind - 2, dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n + 1, -1);
    //     return helper(n, dp);
    // }
    
    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};