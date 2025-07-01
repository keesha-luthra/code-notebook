class Solution {
private:
void func(int index, vector<vector<int>> &ans, vector<int>& nums, vector<int> &subset){
    ans.push_back(subset);
    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i - 1]) continue;
        subset.push_back(nums[i]);
        func(i + 1, ans, nums, subset);
        subset.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        func(0, ans, nums, subset);
        return ans;
    }
};