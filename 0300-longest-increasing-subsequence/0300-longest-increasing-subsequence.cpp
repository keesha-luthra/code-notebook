class Solution {
// private:
//     int helper(int index, int prev_index, vector<int> &nums, vector<vector<int>> &dp){
//         if(index == nums.size()) return 0;
//         if(dp[index][prev_index + 1] != -1) return dp[index][prev_index + 1];
//         int notTake = 0 + helper(index + 1, prev_index, nums, dp);
//         int take = 0;
//         if(prev_index == -1 || nums[index] > nums[prev_index]){
//             take = 1 + helper(index + 1, index, nums, dp);
//         }
//         dp[index][prev_index + 1] = max(notTake, take);
//         return dp[index][prev_index + 1];
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // return helper(0, -1, nums, dp);

        for(int index = n - 1; index >= 0; index--){
            for(int prev_index = index - 1; prev_index >= -1; prev_index--){
                int notTake = 0;
                notTake = dp[index + 1][prev_index + 1];
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                  take = 1 + dp[index + 1][index + 1];
                }
                dp[index][prev_index + 1] = max(notTake, take);
            }
        }
        return dp[0][0];
    }
};