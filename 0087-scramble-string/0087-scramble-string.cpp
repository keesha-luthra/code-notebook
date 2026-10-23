class Solution {
private:
    string a, b;
    int n;
    int memo[31][31][31];

    bool dfs(int i, int j, int len) {
        if (a.compare(i, len, b, j, len) == 0) {
            return true;
        }

        if (memo[i][j][len] != -1) {
            return memo[i][j][len];
        }

        // Prune if character frequencies differ.
        int cnt[26] = {};

        for (int k = 0; k < len; k++) {
            cnt[a[i + k] - 'a']++;
            cnt[b[j + k] - 'a']--;
        }

        for (int x : cnt) {
            if (x != 0) {
                return memo[i][j][len] = 0;
            }
        }

        for (int k = 1; k < len; k++) {
            // No swap
            if (dfs(i, j, k) &&
                dfs(i + k, j + k, len - k)) {
                return memo[i][j][len] = 1;
            }

            // Swap
            if (dfs(i, j + len - k, k) &&
                dfs(i + k, j, len - k)) {
                return memo[i][j][len] = 1;
            }
        }

        return memo[i][j][len] = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        a = s1;
        b = s2;
        n = a.size();

        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, n);
    }
};