class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && candidate2 != nums[i]){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2 == 0 && candidate1 != nums[i]){
                count2 = 1;
                candidate2 = nums[i];
            }
            else if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1) count1++;
            if(nums[i] == candidate2) count2++;
        }
        if(count1 > nums.size()/3) ans.push_back(candidate1);
        if(candidate1 != candidate2 && count2 > nums.size()/3) ans.push_back(candidate2);
        return ans;
    }
};