class Solution {
public:
    // this function returns number of arrays with sum atmost k
    int atMost(vector<int>& nums, int goal){
        if (goal < 0) return 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        int sum = 0;
        while(right < nums.size()){
            sum = sum + nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            ans = ans + (right - left + 1);
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};