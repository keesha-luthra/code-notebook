class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n > 0){
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int reverse_n = reverse(n);
        int dist = abs(n - reverse_n);
        return dist;
    }
};