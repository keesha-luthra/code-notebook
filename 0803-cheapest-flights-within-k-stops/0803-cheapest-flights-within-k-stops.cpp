class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];
            adj[u].push_back({v, p});
        }
        // {stops, node, distance}
        queue<pair<int, pair<int, int>>> q;
        vector<int> prices(n, INT_MAX);
        prices[src] = 0; 
        q.push({0, {src, prices[src]}});
        while(!q.empty()){
            int stops_made = q.front().first;
            int currCity = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(stops_made > k) continue;
            for(auto it : adj[currCity]){
                if(price + it.second < prices[it.first]){
                    prices[it.first] = price + it.second;
                    q.push({stops_made + 1, {it.first, prices[it.first]}});
                }
            }
        }
        if(prices[dst] != INT_MAX) return prices[dst];
        else return -1;
    }
};