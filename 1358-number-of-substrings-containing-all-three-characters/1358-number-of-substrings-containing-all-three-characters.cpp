class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char, int>mpp;
        while(r < s.size()){
            mpp[s[r]]++;
            while(mpp.size() == 3){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            ans = ans + l;
            r++;
        }
        return ans;
    }
};