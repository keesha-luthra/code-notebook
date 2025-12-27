class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Min-heap of free rooms
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        // Min-heap of busy rooms: (endTime, room)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;

            // Free rooms that have finished
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                // Assign immediately
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                // Delay meeting
                auto [finishTime, room] = busy.top();
                busy.pop();
                busy.push({finishTime + duration, room});
                count[room]++;
            }
        }

        // Find room with maximum meetings
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
