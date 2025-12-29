class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            mini = min(mini, prices[i]);
            maxProfit = max(maxProfit, prices[i] - mini);
        }
        return maxProfit;
    }
};