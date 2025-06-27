class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> distance(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        distance[0] = 0;
        distance[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                if(curr + it.second < distance[it.first]){
                    distance[it.first] = curr + it.second;
                    pq.push({distance[it.first], it.first});
                }
            }
        }
        int ans = *max_element(distance.begin(), distance.end());
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};