class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        
        // Set distance to self as 0
        for(int i = 0; i < n; i++){
            cost[i][i] = 0;
        }

        // Populate edges
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            cost[u][v] = w;
            cost[v][u] = w;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (cost[i][k] != INF && cost[k][j] != INF)
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int cnt = 0;
        int city = 0;
        for(int i = 0; i < n; i++){
            cnt = 0;
            for(int j = 0; j < n; j++){
                if(cost[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }
};
