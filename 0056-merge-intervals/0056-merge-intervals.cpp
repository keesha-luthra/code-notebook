class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> current = intervals[0];
        vector<int> next;
        vector<vector<int>> result;
        for(int i = 1; i < intervals.size(); i++){
            next = intervals[i];
            if(next[0] <= current[1]){
                current[1] = max(current[1], next[1]);
            }
            else {
                result.push_back(current);
                current = next;
            }
        }
        result.push_back(current);
        return result;
    }
};