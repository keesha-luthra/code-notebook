class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Sort by start time
        sort(events.begin(), events.end());

        // suffixMax[i] = max value from i to end
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int val = events[i][2];

            // Case 1: take only this event
            ans = max(ans, val);

            // Binary search for next event
            int l = i + 1, r = n - 1, nextIdx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (events[mid][0] >= end + 1) {
                    nextIdx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (nextIdx != -1) {
                ans = max(ans, val + suffixMax[nextIdx]);
            }
        }

        return ans;
    }
};
