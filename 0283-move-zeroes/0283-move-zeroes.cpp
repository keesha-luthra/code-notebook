class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read = 0;
        int write = -1;
        while(read < nums.size()){
            if(nums[read] != 0){
                write++;
                nums[write] = nums[read];
            }
            read++;
        }
        for(int i = write + 1; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};