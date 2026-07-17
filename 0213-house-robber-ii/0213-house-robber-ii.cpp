class Solution {
public:
    int helper(vector<int> nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int pick = nums[i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1(n - 1);
        for(int i = 0; i < n - 1; i++){
            temp1[i] = nums[i];
        }
        vector<int> temp2(n - 1);
        int j = 0;
        for(int i = 1; i < n; i++){
            temp2[j++] = nums[i];
        }
        int ans1 = helper(temp1);
        int ans2 = helper(temp2);
        return max(ans1, ans2);
    }
};