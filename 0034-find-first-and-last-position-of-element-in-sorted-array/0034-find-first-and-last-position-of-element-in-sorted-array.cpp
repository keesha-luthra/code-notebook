class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int start = 0;
        int end = nums.size() - 1;
        int first = nums.size();
        int last = nums.size();
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target){
                first = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        start = 0;
        end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > target){
                last = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        if(first < nums.size() && nums[first] == target) res[0] = first;
        if(last > 0 && nums[last - 1] == target) res[1] = last - 1;
        return res;
    }
};