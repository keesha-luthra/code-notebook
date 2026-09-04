class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0)
            return false;

        // Frequency of each card
        map<int, int> freq;

        for (int card : hand) {
            freq[card]++;
        }

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : freq) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int start = pq.top();

            // Create a group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                // Card doesn't exist
                if (freq[card] == 0)
                    return false;

                freq[card]--;

                // If frequency becomes 0, it should be removed
                // from the heap when it reaches the top.
            }

            // Remove cards whose frequency became 0
            while (!pq.empty() && freq[pq.top()] == 0) {
                pq.pop();
            }
        }

        return true;
    }
};