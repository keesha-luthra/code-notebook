class Solution {
private:
int helper(vector<int> &nums){
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr = 0;
    for(int i = 2; i < nums.size(); i++){
        int pick = nums[i] + prev2;
        int notpick = prev1;
        curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return helper(nums);
    }
};