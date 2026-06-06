class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int cnt = 1;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(curr > mid){
                cnt++;
                curr = nums[i];
            }
        }
        if(cnt <= k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k == nums.size()) return *max_element(nums.begin(), nums.end());
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int mid = 0;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(nums, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};