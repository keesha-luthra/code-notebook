class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        diff[0][0] = 0;
        q.push({diff[0][0], {0, 0}});
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {-1, 0, 1, 0};
        while(!q.empty()){
            int effort = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newDiff = abs(heights[nr][nc] - heights[r][c]);
                    int neffort = max(effort, newDiff);
                    if(neffort < diff[nr][nc]){
                        diff[nr][nc] = neffort;
                        q.push({neffort, {nr, nc}});
                    }
                }
            }
        }
        return diff[m - 1][n - 1];
    }
};