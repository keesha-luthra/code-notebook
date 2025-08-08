class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // int n = nums.size();
        // k = k % n;
        // vector<int> temp(k, - 1);
        // int j = 0;
        // for(int i = nums.size() - k; i < nums.size(); i++){
        //     temp[j] = nums[i];
        //     j++;
        // }
        // for(int i = n - k - 1; i >= 0; i--){
        //     nums[i + k] = nums[i];
        // }
        // j = 0;
        // for(int i = 0; i < k; i++){
        //     nums[i] = temp[j];
        //     j++;
        // }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
