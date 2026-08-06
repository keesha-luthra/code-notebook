class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int req = target - nums[i];
            if(mpp.find(req) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[req]);
            }
            else{
                mpp[nums[i]] = i;
            }
        }
        return ans;
    }
};
