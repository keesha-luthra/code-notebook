class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});
        }

        sort(numWithIndex.begin(), numWithIndex.end());

        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int sum = numWithIndex[start].first + numWithIndex[end].first;
            if (sum == target) {
                return {numWithIndex[start].second, numWithIndex[end].second};
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        return {}; // In case no valid pair is found
    }
};
