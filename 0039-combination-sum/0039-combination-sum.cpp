class Solution {
private:
void func(int index, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(index >= candidates.size() || target < 0){
        return;
    }
    temp.push_back(candidates[index]);
    func(index, target - candidates[index], candidates, ans, temp);
    temp.pop_back();
    func(index + 1, target, candidates, ans, temp);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, target, candidates, ans, temp);
        return ans;
    }
};