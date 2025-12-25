class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int read = 1;
        int write = 0;
        while(read < nums.size()){
            if(nums[read] != nums[write]){
                write++;
                nums[write] = nums[read];
            }
            read++;
        }
        return write + 1;
    }
};