class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);

            if (i > 1) {
                fact[i] = fact[i - 1] * i;
            }
        }

        k--;  // Convert to zero-based indexing.

        string ans;

        for (int i = n; i >= 1; i--) {
            int index = k / fact[i - 1];

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= fact[i - 1];
        }

        return ans;
    }
};