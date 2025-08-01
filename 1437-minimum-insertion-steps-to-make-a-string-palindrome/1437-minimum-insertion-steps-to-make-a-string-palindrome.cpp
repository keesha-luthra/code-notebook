class Solution {
public:
    int minInsertions(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int cnt = 0;
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s_rev[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cnt = n - dp[n][n];
        return cnt;
    }
};