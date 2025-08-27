class Solution {
public:
    int reverse(int x) {
        int revx = 0;
        int digit = 0;
        while(x != 0){
            digit = x % 10;
            if(revx < INT_MIN/10) return 0;
            if(revx > INT_MAX/10) return 0;
            revx = revx * 10 + digit;
            x = x/10;
        }
        if(revx < INT_MIN) return 0;
        if(revx > INT_MAX) return 0;
        return revx;
    }
};