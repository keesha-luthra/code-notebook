class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> seen;
        int maxLen = 0;
        while(r < s.size()){
            while (seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};