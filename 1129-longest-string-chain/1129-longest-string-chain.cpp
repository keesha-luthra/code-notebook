class Solution {
private:
bool check(string &s1, string &s2){
    if(s1.size() + 1 != s2.size()) return false;
    int first = 0;
    int second = 0;
    while(second < s2.size()){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            second++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false;
}
public:
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        int n = arr.size();
        vector<int>dp(n, 1);
        for(int index = 0; index < n; index++){
            for(int prev = 0; prev < index; prev++){
                if(check(arr[prev], arr[index]) && dp[prev] + 1 > dp[index]){
                    dp[index] = 1 + dp[prev];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};