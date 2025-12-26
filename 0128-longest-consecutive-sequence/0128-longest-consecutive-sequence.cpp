class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> s;
        for(auto it : nums){
            s.insert(it);
        }   
        for(auto it : s){
            // it - 1 does not exist 
            if(s.find(it - 1) == s.end()){
                int len = 1;
                int curr = it + 1;
                while(s.find(curr) != s.end()){
                    len++;
                    curr++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};