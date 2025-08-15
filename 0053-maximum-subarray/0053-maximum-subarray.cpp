class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int sum = 0;
        // int maxSum = INT_MIN;
        // for(int i = 0; i < nums.size(); i++){
        //     sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum = sum + nums[j];
        //         maxSum = max(maxSum, sum);
        //     }
        // }
        // return maxSum;

        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};
