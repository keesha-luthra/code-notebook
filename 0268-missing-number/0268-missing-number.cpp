class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int flag = 0;
        for(int i = 0; i <= nums.size(); i++){
            flag = 0;
            for(int j = 0; j < nums.size(); j++){
                if(i == nums[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return i;
        }
        return 0;
    }
};