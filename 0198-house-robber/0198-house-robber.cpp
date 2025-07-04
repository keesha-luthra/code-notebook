class Solution {
private:
int helper(int n, vector<int> &dp, vector<int> &nums){
    if(n == 0) return dp[0] = nums[0];
    if(n == 1) return dp[1] = max(nums[0], nums[1]);
    if(dp[n] != -1) return dp[n];
    int pick = nums[n] + helper(n - 2, dp, nums);
    int notpick = helper(n - 1, dp, nums);
    return dp[n] = max(pick, notpick);
}
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        int index = nums.size() - 1;
        return helper(index, dp, nums);
    }
};