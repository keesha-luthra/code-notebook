class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < 32; i++){
            count = 0;
            for(auto it : nums){
                if(it & (1 << i)) count++;
            }

            if(count % 3){
                ans |= 1 << i;
            }
        }
        return ans;
    }
};