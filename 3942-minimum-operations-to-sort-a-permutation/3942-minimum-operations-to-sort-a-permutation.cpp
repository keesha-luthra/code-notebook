class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // Check if nums is a cyclically increasing permutation.
        bool inc = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                inc = false;
                break;
            }
        }

        if (inc) {
            int k = nums[0];
            ans = min(ans, min((n - k) % n, k + 2));
        }

        // Check if nums is a cyclically decreasing permutation.
        bool dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] - i + n) % n) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int k = (n - 1 - nums[0] + n) % n;
            ans = min(ans, 1 + min(k, (n - k) % n));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};