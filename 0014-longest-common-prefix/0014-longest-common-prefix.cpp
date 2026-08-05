class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        } 
        char c;
        int flag = 0;
        string result = "";
        for(int i = 0; i < strs[0].length(); i++){
            c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(c != strs[j][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                result.push_back(c);
        }     
        return result;
    }
};