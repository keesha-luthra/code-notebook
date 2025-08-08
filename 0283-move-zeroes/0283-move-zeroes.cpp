class Solution {
private:
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
public:
    void moveZeroes(vector<int>& nums) {
        // vector<int> temp;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] != 0) temp.push_back(nums[i]);
        // }
        // int s = temp.size();
        // for(int i = 0; i < s; i++){
        //     nums[i] = temp[i];
        // }
        // for(int i = s; i < nums.size(); i++){
        //     nums[i] = 0;
        // }
        int i = 0;
        int flag = 0;
        for(int t = 0; t < nums.size(); t++){
            if(nums[t] == 0) {
                i = t;
                flag = 1;
                break;
            }
        }
        if(flag == 0) return;
        int j = i + 1;
        while(i < nums.size() && j < nums.size()){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};