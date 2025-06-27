class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);
        const int MOD = 1e9 + 7;
        distance[0] = 0;
        ways[0] = 1;
        q.push({0, 0});
        while(!q.empty()){
            long long curr = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adj[node]){
                int next = it.first;
                int wt = it.second;
                if(curr + wt < distance[next]){
                    distance[next] = curr + wt;
                    q.push({distance[next], next});
                    ways[next] = ways[node];
                }
                else if(curr + wt == distance[next]){
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
