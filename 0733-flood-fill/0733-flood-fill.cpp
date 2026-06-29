class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int oldcolor, int color, int m, int n){
        image[r][c] = color;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == oldcolor){
                dfs(nrow, ncol, image, oldcolor, color, m, n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];
        if(color == oldcolor) return image;
        dfs(sr, sc, image, oldcolor, color, m, n);
        return image;
    }
};