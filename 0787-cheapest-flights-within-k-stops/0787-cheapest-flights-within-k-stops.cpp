class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            adj[u].push_back({v, wt});
        }

        // Minimum cost to reach each city
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        // {node, currentCost}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int flightsTaken = 0;

        while (!q.empty() && flightsTaken <= k) {

            int sz = q.size();

            // Copy current costs
            vector<int> temp = cost;

            while (sz--) {

                auto curr = q.front();
                q.pop();

                int node = curr.first;
                int currCost = curr.second;

                for (auto &it : adj[node]) {

                    int next = it.first;
                    int wt = it.second;

                    int newCost = currCost + wt;

                    if (newCost < temp[next]) {
                        temp[next] = newCost;
                        q.push({next, newCost});
                    }
                }
            }

            // Update costs after finishing this level
            cost = temp;
            flightsTaken++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};