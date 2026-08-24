class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            // if mid is odd make it even
            if(mid % 2 != 0) mid--;

            // pairing is fine
            if(nums[mid] == nums[mid + 1]){
                start = mid + 2;
            }

            // pairing breaks
            else{
                end = mid;
            }
        }
        return nums[start];
    }
};