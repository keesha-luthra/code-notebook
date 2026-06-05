class Solution {
public:
    long long check(vector<int>& piles, int mid){
        long long totalHours = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHours += (piles[i] + mid - 1) / mid;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid = 0;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};