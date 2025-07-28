class Solution {
// private:
// int helper(int index, int buy, vector<int>& prices, int n, int cap, vector<vector<vector<int>>> &dp){
//     if(cap == 0) return 0;
//     if(index == n) return 0;
//     int profit = 0;
//     // you can buy
//     if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
//     if(buy == 1){
//         int bought = -prices[index] + helper(index + 1, 0, prices, n, cap, dp);
//         int notBought = 0 + helper(index + 1, 1, prices, n, cap, dp);
//         profit = max(bought, notBought);
//     }
//     // you cannot buy you have to sell first
//     else{
//         int sold = prices[index] + helper(index + 1, 1, prices, n, cap - 1, dp);
//         int notSold = 0 + helper(index + 1, 0, prices, n, cap, dp);
//         profit = max(sold, notSold);
//     }
//     dp[index][buy][cap] = profit;
//     return dp[index][buy][cap];
// }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return helper(0, 1, prices, n, 2, dp);
        int profit = 0;
        for(int index = n - 1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= 2; cap++){
                                    if(buy == 1){
        int bought = -prices[index] + dp[index + 1][0][cap];
        int notBought = 0 + dp[index + 1][1][cap];
        profit = max(bought, notBought);
    }
    // you cannot buy you have to sell first
    else{
        int sold = prices[index] + dp[index + 1][1][cap - 1];
        int notSold = 0 + dp[index + 1][0][cap];
        profit = max(sold, notSold);
    }
    dp[index][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};