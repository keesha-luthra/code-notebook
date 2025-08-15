class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(i == j) continue;
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            int req = target - nums[i];
            if(mpp.find(req) != mpp.end()){
                return {i, mpp[req]};
            }
            else{
                mpp[curr] = i;
            } 
        }
        return {};
    }
};
