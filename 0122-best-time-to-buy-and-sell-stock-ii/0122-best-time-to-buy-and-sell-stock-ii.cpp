class Solution {
// private:
// int helper(int index, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
//     if(index == n) return 0;
//     int profit = 0;
//     // you can buy
//     if(dp[index][buy] != -1) return dp[index][buy];
//     if(buy == 1){
//         int bought = -prices[index] + helper(index + 1, 0, prices, n, dp);
//         int notBought = 0 + helper(index + 1, 1, prices, n, dp);
//         profit = max(bought, notBought);
//     }
//     // you cannot buy you have to sell first
//     else{
//         int sold = prices[index] + helper(index + 1, 1, prices, n, dp);
//         int notSold = 0 + helper(index + 1, 0, prices, n, dp);
//         profit = max(sold, notSold);
//     }
//     dp[index][buy] = profit;
//     return dp[index][buy];
// }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp (n + 1, vector<int>(2, 0));
        // return helper(0, 1, prices, n, dp);
        int profit = 0;
        for(int index = n - 1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                if(buy == 1){
                    int bought = -prices[index] + dp[index + 1][0];
                    int notBought = 0 + dp[index + 1][1];
                    profit = max(bought, notBought);
                }
                // you cannot buy you have to sell first
                else{
                    int sold = prices[index] + dp[index + 1][1];
                    int notSold = 0 + dp[index + 1][0];
                    profit = max(sold, notSold);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};