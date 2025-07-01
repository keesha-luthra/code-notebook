class Solution {
private:
void func(int index, string digits, string temp, vector<string> &ans, vector<string> &mpp){
    if(index >= digits.length()){
        ans.push_back(temp);
        return;
    }
    string letters = mpp[digits[index] - '2'];
    for(auto it : letters){
        temp.push_back(it);
        func(index + 1, digits, temp, ans, mpp);
        temp.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mpp= {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.empty()) return ans;
        string temp;
        func(0, digits, temp, ans, mpp);
        return ans;
    }
};