class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        q.push({0, 0});
        int path = 1;
        grid[0][0] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dc[] = {-1,  0,  1,-1, 1,-1, 0, 1};
                for(int i = 0; i < 8; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                    if(r == n - 1 && c == n - 1) return path;
                }
            }
            path++;
        }
        return -1;
    }
};
