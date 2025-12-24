class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_count = 0;
        int max_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                curr_count++;
            if(nums[i] == 0)
                curr_count = 0;
            if(curr_count > max_count)
                max_count = curr_count;
        }
        return max_count;
    }
};