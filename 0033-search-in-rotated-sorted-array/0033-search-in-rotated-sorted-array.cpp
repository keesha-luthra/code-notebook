class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        // Continue while there are elements to search
        while (left <= right) {

            // Calculate middle index without overflow
            int mid = left + (right - left) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Check whether the left half is sorted
            if (nums[left] <= nums[mid]) {

                // Target lies within the sorted left half
                if (nums[left] <= target && target < nums[mid]) {

                    // Discard the right half
                    right = mid - 1;
                }
                else {
                    // Target must be in the right half
                    left = mid + 1;
                }
            }

            // Otherwise, the right half is sorted
            else {

                // Check whether target lies in the sorted right half
                if (nums[mid] < target && target <= nums[right]) {

                    // Discard the left half
                    left = mid + 1;
                }
                else {
                    // Target must be in the left half
                    right = mid - 1;
                }
            }
        }

        // Target does not exist
        return -1;
    }
};