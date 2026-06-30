class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> outDegrees(m, 0);
        for(int i = 0; i < m; i++){
            outDegrees[i] = graph[i].size();
        }
        queue<int> q;
        vector<int> safe;
        for(int i = 0; i < m; i++){
            if(outDegrees[i] == 0) q.push(i);
        }
        vector<vector<int>> rev(m);
        for(int i = 0; i < m; i++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto parent : rev[node]){
                outDegrees[parent]--;
                if(outDegrees[parent] == 0) q.push(parent);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};