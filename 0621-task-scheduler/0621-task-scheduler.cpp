class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max Heap
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        // {remaining frequency, time when task becomes available}
        queue<pair<int, int>> q;

        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            // If a task is available, take the most frequent one
            if (!pq.empty()) {
                int f = pq.top();
                pq.pop();

                f--;

                // If task still remains, put it in cooldown
                if (f > 0) {
                    q.push({f, time + n});
                }
            }

            // Check if any task has finished its cooldown
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};