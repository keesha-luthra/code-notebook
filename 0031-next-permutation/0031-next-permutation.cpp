class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find pivot 
        int i = 0;
        for(i = nums.size() - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]) break;
        }
        // i is now pivot 

        // pivot does not exist
        if(i < 0) reverse(nums.begin(), nums.end());

        else{
            // find smallest greater element than nums[i]
            int j = 0;
            for(j = nums.size() - 1; j >= 0; j--){
                if(nums[j] > nums[i]) break;
            }
            // nums[j] is now the smallest greater element than nums[i]

            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};