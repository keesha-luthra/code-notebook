class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int temp = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     nums[i - 1] = nums[i];
        // }
        // nums[nums.size() - 1] = temp;

        int n = nums.size(); 
        k = k % n;
        k = n - k;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
