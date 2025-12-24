class Solution {
public:
    int secondHighest(string s) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(int i = 0; i < s.length(); i++){
            if(s[i] <= '9' && s[i] >= '0'){
                int d = s[i] - '0';
                if(d > max1){
                    max2 = max1;
                    max1 = d;
                }
                if(d > max2 && d < max1)
                    max2 = d;
            }
        }
        if(max2 == INT_MIN) return -1;
            else return max2;
    }
};