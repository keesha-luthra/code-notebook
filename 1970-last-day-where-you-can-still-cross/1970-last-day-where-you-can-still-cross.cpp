class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = row * col;
        int ans = 0;

        vector<int> dir = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));

            // Flood cells for given day
            for (int i = 0; i < day; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int,int>> q;

            // Start BFS from top row
            for (int c = 0; c < col; c++) {
                if (grid[0][c] == 0) {
                    q.push({0, c});
                    grid[0][c] = 1; // mark visited
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == row - 1) return true;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dir[d];
                    int nc = c + dir[d + 1];

                    if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
