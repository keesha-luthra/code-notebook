class Solution {
private:
void func(int index, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = index; i < candidates.size(); i++){
        if(i > index && candidates[i] == candidates[i - 1])continue;
        if(candidates[i] > target) break;
        else{
            ds.push_back(candidates[i]);
            func(i + 1, target - candidates[i], candidates, ds, ans);
            ds.pop_back();
        }
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        func(0, target, candidates, ds, ans);
        return ans;
    }
};