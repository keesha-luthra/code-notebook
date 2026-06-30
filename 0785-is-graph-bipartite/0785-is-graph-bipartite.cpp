class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        queue<int> q;
        q.push(node);
        visited[node] = 0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(auto it : graph[current]){
                if(visited[it] == -1){
                    visited[it] = 1 - visited[current];
                    q.push(it);
                }
                else if(visited[it] == visited[current]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> visited(m, -1);
        for(int i = 0; i < m; i++){
            if(visited[i] == -1){
                if(!bfs(i, graph, visited)) return false;
            }
        }
        return true;
    }
};