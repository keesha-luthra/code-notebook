class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Use characters from s2 only.
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] &&
                    (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; i++) {
            // Use characters from s1 only.
            dp[0] = dp[0] &&
                    (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= n; j++) {
                char c = s3[i + j - 1];

                bool fromS1 =
                    dp[j] && s1[i - 1] == c;

                bool fromS2 =
                    dp[j - 1] && s2[j - 1] == c;

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
};