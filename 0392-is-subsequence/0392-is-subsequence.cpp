class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;  // matched a character in s
            }
            j++;  // move in t regardless
        }
        return i == s.length();  // did we match all of s?
    }
};
