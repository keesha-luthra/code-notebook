class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for(int i = 1; i <= numRows - 1; i++){
            vector<int> row(i + 1, 0);
            row[0] = 1;
            row[i] = 1;
            for(int j = 1; j < i; j++){
                row[j] = result[i - 1][j] + result[i - 1][j - 1];
            }
            result.push_back(row);
        }
        return result;
    }
};