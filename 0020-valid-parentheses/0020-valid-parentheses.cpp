class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mpp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.empty()) return false;
                
                if(st.top() != mpp[ch]) return false;
                
                st.pop();
            }
        }
        return st.empty();
    }
};