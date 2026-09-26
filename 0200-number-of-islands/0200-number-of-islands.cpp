class Solution {
public:
    // DFS to visit all the land cells ('1') connected to the current cell
    void dfs(int r, int c, vector<vector<int>>& visited,
             vector<vector<char>>& grid, int m, int n) {

        // Mark the current cell as visited
        visited[r][c] = 1;

        // Direction arrays to explore the 4 adjacent cells:
        // Up, Right, Down, Left
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // Explore all 4 possible directions
        for(int i = 0; i < 4; i++) {

            // Calculate the coordinates of the neighboring cell
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            // Check if the neighboring cell is within the grid boundaries,
            // contains land ('1'), and has not been visited yet
            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               grid[nrow][ncol] == '1' &&
               !visited[nrow][ncol]) {

                // Recursively visit the neighboring land cell
                // and explore all land connected to it
                dfs(nrow, ncol, visited, grid, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        // Get the number of rows and columns in the grid
        int m = grid.size();
        int n = grid[0].size();

        // Stores the total number of islands found
        int ans = 0;

        // Create a visited matrix initialized to 0
        // 0 = not visited, 1 = visited
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Traverse every cell in the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // If the current cell is land and has not been visited,
                // it is the starting point of a new island
                if(!visited[i][j] && grid[i][j] == '1') {

                    // Run DFS to visit all land cells belonging
                    // to this island
                    dfs(i, j, visited, grid, m, n);

                    // Increment the island count after completing DFS
                    ans++;
                }
            }
        }

        // Return the total number of islands
        return ans;
    }
};