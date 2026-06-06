class Solution {
public:
    int missingCount(vector<int>& arr, int mid){
        int missing = arr[mid] - (mid + 1);
        return missing;
    }
    int findKthPositive(vector<int>& arr, int k) {
        if(missingCount(arr, 0) >= k) return k;
        int low = 1;
        int high = arr.size() - 1;
        int mid = 0;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(missingCount(arr, mid) >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(ans == 0){
            int n = arr.size();
            int needed = k - missingCount(arr, n - 1);
            return arr[n - 1] + needed;
        } 
        int prev_missing = missingCount(arr, ans - 1);
        int req = k - prev_missing;
        return arr[ans - 1] + req;
    }
};