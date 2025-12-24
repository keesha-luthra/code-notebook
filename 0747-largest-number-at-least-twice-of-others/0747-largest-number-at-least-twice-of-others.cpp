class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        int check = 1;
        for(int i = 0; i < nums.size(); i++){
            if(i == index) continue;
            if(max < 2 * nums[i])
                return -1;
        }
        return index;
    }
};