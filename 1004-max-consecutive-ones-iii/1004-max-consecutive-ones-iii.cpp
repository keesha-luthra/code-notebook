class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        int maxLen = 0;
        while(right < nums.size()){
            if(nums[right] == 0) cnt++;
            while(cnt > k){
                if(nums[left] == 0){
                    cnt--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right = right + 1;
        }
        return maxLen;
    }
};