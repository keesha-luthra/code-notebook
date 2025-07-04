class Solution {
private:
int helper(vector<int> &dp, vector<int> &nums){
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
        int pick = nums[i] + dp[i - 2];
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[nums.size() - 1];
}
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        int index = nums.size() - 1;
        return helper(dp, nums);
    }
};