class Solution {
private:
int findMin(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    if(c <= a && c <= b) return c;
    return 0;
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(m, - 1));
        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < m; j++){
                int up = INT_MAX;
                int ld = INT_MAX;
                int rd = INT_MAX;
                if(i > 0) up = matrix[i][j] + dp[i - 1][j];
                if(i > 0 && j > 0) ld = matrix[i][j] + dp[i - 1][j - 1];
                if(i > 0 && j < m - 1) rd = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = findMin(up, ld, rd);
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            mini = min(mini, dp[m - 1][j]);
        }
        return mini;
    }
};