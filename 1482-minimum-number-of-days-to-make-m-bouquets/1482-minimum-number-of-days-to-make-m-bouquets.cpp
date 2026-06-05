class Solution {
public:
    int check(vector<int>& bloomDay, int m, int k, int mid){
        int count = 0;
        int total = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            // ith flower has bloomed at day mid
            if(bloomDay[i] <= mid){
                count += 1;
                if(count == k){
                    total += 1;
                    count = 0;
                }
            }
            else count = 0;
        }
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)k * m > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mid = 0;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid) >= m){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};