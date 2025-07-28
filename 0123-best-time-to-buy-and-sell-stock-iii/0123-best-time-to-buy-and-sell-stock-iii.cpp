class Solution {
private:
int helper(int index, int buy, vector<int>& prices, int n, int cap, vector<vector<vector<int>>> &dp){
    if(cap == 0) return 0;
    if(index == n) return 0;
    int profit = 0;
    // you can buy
    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
    if(buy == 1){
        int bought = -prices[index] + helper(index + 1, 0, prices, n, cap, dp);
        int notBought = 0 + helper(index + 1, 1, prices, n, cap, dp);
        profit = max(bought, notBought);
    }
    // you cannot buy you have to sell first
    else{
        int sold = prices[index] + helper(index + 1, 1, prices, n, cap - 1, dp);
        int notSold = 0 + helper(index + 1, 0, prices, n, cap, dp);
        profit = max(sold, notSold);
    }
    dp[index][buy][cap] = profit;
    return dp[index][buy][cap];
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n, vector<vector<int>>(2, vector<int>(3, - 1)));
        return helper(0, 1, prices, n, 2, dp);
    }
};