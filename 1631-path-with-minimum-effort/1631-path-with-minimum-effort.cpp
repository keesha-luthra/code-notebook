class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // (effort, row, col)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int currEffort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == m - 1 && c == n - 1) return currEffort;
            if(currEffort > dist[r][c]) continue;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int edge = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(edge, currEffort);
                    if(newEffort < dist[nr][nc]){
                        pq.push({newEffort, {nr, nc}});
                        dist[nr][nc] = newEffort;
                    }
                }
            }
        }
        return 0;
    }
};