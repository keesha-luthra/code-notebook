class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for(int i = 0; i < t.size(); i++){
            target[t[i]]++;
        }
        int req = target.size();
        int left = 0;
        int right = 0;
        unordered_map<char, int> mpp;
        int have = 0;
        string ans = "";
        int len = INT_MAX;
        int best_start = INT_MAX;
        while(right < s.size()){
            char ch = s[right];
            mpp[ch]++;
            if(target.count(ch) && target[ch] == mpp[ch]) have++;
            while(have == req){
                int current_len = right - left + 1;
                if(current_len < len){
                    len = current_len;
                    best_start = left;
                }
                mpp[s[left]]--;
                if(target.count(s[left]) && mpp[s[left]] < target[s[left]]) have--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            right++;
        }
        if(len == INT_MAX) return ans;
        else return s.substr(best_start, len);
    }
};