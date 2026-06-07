class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int ans = 0;
        int cnt = 0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0) cnt++;
            while(cnt > k){
                if(nums[l] % 2 != 0) cnt--;
                l++;
            }
            ans = ans + (r - l + 1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};