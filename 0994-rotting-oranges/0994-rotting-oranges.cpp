class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int ans = 0;
        while(!q.empty() && fresh > 0){
            int currentSize = q.size();
            ans++;
            for(int i = 0; i < currentSize; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j ++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }

                }
            }
        }
        if (fresh > 0) return -1;
        return ans;
    }
};