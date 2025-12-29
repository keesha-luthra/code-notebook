class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0;
        for(int i = 0; i < nums.size(); i++){
            a ^= nums[i];
        }
        int b = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            b ^= i;
        }
        return a^b;
    }
};