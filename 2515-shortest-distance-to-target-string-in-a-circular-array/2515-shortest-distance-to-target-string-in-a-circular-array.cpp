class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        int flag = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == target){
                int right = abs(i - startIndex);
                int left = n - right;
                ans = min(ans, min(right, left));
                flag = 1;
            }
        }
        if (flag == 1) return ans;
        return -1;
    }
};