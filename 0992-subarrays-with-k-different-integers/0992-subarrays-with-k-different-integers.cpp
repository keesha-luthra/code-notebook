class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        unordered_map<int, int> mpp;
        int res = 0;
        while(right < nums.size()){
            mpp[nums[right]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            res = res + (right - left + 1);
            right++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k == nums.size()) return nums.size();
        return atMost(nums, k) - atMost(nums, k -1);
    }
};