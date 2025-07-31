class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>dp(n, 1), hash(n);
        int maxi = INT_MIN;
        for(int index = 0; index < n; index++){
            hash[index] = index;
            for(int prev = 0; prev < index; prev++){
                if(arr[index] % arr[prev] == 0 && dp[prev] + 1 > dp[index]){
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }
        }
        int last_index = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                last_index = i;
            }
        }
        
        vector<int> ans;
        while(hash[last_index] != last_index){
            ans.push_back(arr[last_index]);
            last_index = hash[last_index];
        }
        ans.push_back(arr[last_index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};