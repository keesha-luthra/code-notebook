class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> mpp;
        int ans = 0;
        int req = 0;
        int maxFreq = 0;
        while(right < s.size()){
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);
            while((right - left + 1) - maxFreq > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
