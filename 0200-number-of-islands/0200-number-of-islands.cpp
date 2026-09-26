class Solution {
public:
    int rows, cols;

    // DFS explores all land cells connected to (r, c)
    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Stop if out of bounds or the cell is water/already visited
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] != '1') {
            return;
        }

        // Mark this land cell as visited by turning it into water
        grid[r][c] = '0';

        // Explore the four adjacent directions
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {

        // Get the grid dimensions
        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;

        // Visit every cell in the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // A new island starts wherever unvisited land is found
                if (grid[r][c] == '1') {

                    // Count this island
                    islands++;

                    // Visit and mark every cell belonging to it
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};