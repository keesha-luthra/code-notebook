class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        memo = {}

        def dp(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            if j == n:
                return i == m

            first_match = (
                i < m and
                (p[j] == s[i] or p[j] == '.')
            )

            if j + 1 < n and p[j + 1] == '*':
                result = (
                    dp(i, j + 2) or
                    (first_match and dp(i + 1, j))
                )
            else:
                result = (
                    first_match and
                    dp(i + 1, j + 1)
                )

            memo[(i, j)] = result
            return result

        return dp(0, 0)