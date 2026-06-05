class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        int ans = INT_MAX;
        while(low <= high){
            mid = low + (high - low) / 2;
            // left half sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // right half is sorted
            else if (nums[mid] <= nums[high]){
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};