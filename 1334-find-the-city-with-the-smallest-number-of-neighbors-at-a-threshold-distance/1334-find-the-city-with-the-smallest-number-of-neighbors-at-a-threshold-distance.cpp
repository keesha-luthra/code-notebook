class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int k = 0; k < n; k++){
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // if k is not an intermediate node on the path from i to j
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8){
                        continue;
                    }
                    
                    // if there is no direct edge between i and j
                    else if(dist[i][j] == 1e8){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    
                    // if there is a direct edge between i and j
                    else if(dist[i][j] != 1e8){
                        dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                    }
                }
            }
        }

        int cntCity = n;
        int ans = -1;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(city != adjCity && dist[city][adjCity] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                ans = city;
            }
        }
        return ans;
    }
};
