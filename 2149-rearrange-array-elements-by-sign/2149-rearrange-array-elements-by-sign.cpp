class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int i = 0;
        // int j = 0;
        // while(i < nums.size()){
        //     if(i % 2 == 0 && nums[i] > 0) i++;
        //     else if(i % 2 != 0 && nums[i] < 0) i++;
        //     else{
        //         j = i + 1;
        //         while(j < nums.size() && signbit(nums[i]) == signbit(nums[j])) j++;
        //         swap(nums[i], nums[j]);
        //     }
        // }
        // return nums;



        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        vector<int> result(nums.size(), 0);
        int p = 0;
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                result[i] = pos[p++];
            }
            else{
                result[i] = neg[n++];
            }
        }
        return result;
    }
};