class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el) cnt++;
            else cnt--;
        }
        int freq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el) freq++;
        }
        if(freq > nums.size() / 2) return el;
        else return -1;
    }
};