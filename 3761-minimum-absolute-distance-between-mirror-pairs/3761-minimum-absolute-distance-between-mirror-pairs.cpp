class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n > 0){
            int r = n % 10;
            rev = rev * 10 + r;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: store all indices
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: for each index
        for(int i = 0; i < n; i++){
            int rev = reverse(nums[i]);

            if(mp.find(rev) != mp.end()){
                auto &vec = mp[rev];

                // Step 3: find first index > i
                auto it = upper_bound(vec.begin(), vec.end(), i);

                if(it != vec.end()){
                    int j = *it;
                    ans = min(ans, j - i);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};