class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0;
        int negIndex = 1;
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans[posIndex] = nums[i];
                posIndex = posIndex + 2;
            }
            else{
                ans[negIndex] = nums[i];
                negIndex = negIndex + 2;
            }
        }
        return ans;
    }
};