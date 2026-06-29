class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& grid, int m, int n){
        visited[r][c] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                dfs(nrow, ncol, visited, grid, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =  grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, visited, grid, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};