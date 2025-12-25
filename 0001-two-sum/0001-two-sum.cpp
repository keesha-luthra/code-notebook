class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int req = target - nums[i];
            if(mp.find(req) != mp.end()){
                result.push_back(i);
                result.push_back(mp[req]);
                break;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return result;
    }
};
