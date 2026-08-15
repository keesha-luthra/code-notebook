class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(minProd, maxProd);
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            res = max(res, maxProd);
        }
        return res;
    }
};