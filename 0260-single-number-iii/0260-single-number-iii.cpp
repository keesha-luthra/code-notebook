class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for(auto it : nums){
            xorAll ^= it;
        }
        unsigned int mask = xorAll & (-(unsigned int)xorAll);
        int a = 0;
        int b = 0;
        vector<int> ans;
        for(auto it : nums){
            if(it & mask) a ^= it;
            else b ^= it; 
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};