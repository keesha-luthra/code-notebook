class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int result = 0;
        // unordered_map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it : mp){
        //     if(it.second == 1)
        //         result = it.first;
        // }
        // return result;

        int ans = 0;
        for(auto it : nums){
            ans ^= it;
        }
        return ans;
    }
};