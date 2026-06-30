class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, int m, int n){
        board[r][c] = 'S';
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O'){
                dfs(nr, nc, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 1st and last row
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, m, n);
            }
            if(board[m - 1][i] == 'O'){
                dfs(m - 1, i, board, m, n);
            }
        }
        // 1st and last column
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, m, n);
            }
            if(board[i][n - 1] == 'O'){
                dfs(i, n - 1, board, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
                else board[i][j] = 'X';
            }
        }
    }
};