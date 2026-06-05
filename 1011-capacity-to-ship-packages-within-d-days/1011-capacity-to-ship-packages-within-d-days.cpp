class Solution {
public:
    int check(vector<int>& weights, int mid){
        int curr = 0;
        int days = 1;
        for(int i = 0; i < weights.size(); i++){
            curr += weights[i];
            if(curr > mid){
                days += 1;
                curr = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);
        int mid = 0;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(weights, mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};