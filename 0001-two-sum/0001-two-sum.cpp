class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //         }
        //     }
        // }
        // return ans;

        // Optimized
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(mpp.find(complement) != mpp.end()){
                ans.push_back(mpp[complement]);
                ans.push_back(i);
                return ans;
            }
            else{
                mpp[nums[i]] = i;
            }
        }
        return ans;
    }
};
