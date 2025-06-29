class Solution {
private:
void func(int index, vector<int> &temp, int size, vector<int>& nums, vector<vector<int>> &ans){
    if(index >= size){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    func(index + 1, temp, size, nums, ans);
    temp.pop_back();
    func(index + 1, temp, size, nums, ans);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, temp, n, nums, ans);
        return ans;
    }
};