class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<int>>& grid, int m, int n){
        visited[r][c] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, visited, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // 1st row
        for(int i = 0; i < n; i++){
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(0, i, visited, grid, m, n);
            }
        }
        // last row
        for(int i = 0; i < n; i++){
            if(!visited[m - 1][i] && grid[m - 1][i] == 1){
                dfs(m - 1, i, visited, grid, m, n);
            }
        }
        // 1st column
        for(int i = 0; i < m; i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i, 0, visited, grid, m, n);
            }
        }
        // last column
        for(int i = 0; i < m; i++){
            if(!visited[i][n - 1] && grid[i][n - 1] == 1){
                dfs(i, n -1, visited, grid, m, n);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) ans++;
            }
        }
        return ans;
    }
};