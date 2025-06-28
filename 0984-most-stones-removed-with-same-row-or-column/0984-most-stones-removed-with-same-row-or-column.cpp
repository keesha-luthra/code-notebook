class DisjointSet{
    vector<int> parent, size;
    public:
        DisjointSet(int V){
            parent.resize(V);
            size.resize(V);
            for(int i = 0; i < V; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findParent(int node){
            if(parent[node] == node) return node;
            else
                return parent[node] = findParent(parent[node]);
        }
        
        void unionBySize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv) return;
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] = size[pv] + size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] = size[pu] + size[pv];
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> validNodes;
        for(auto it : stones){
            int u = it[0];
            int v = it[1] + maxRow + 1;
            ds.unionBySize(u, v);
            validNodes[u] = 1;
            validNodes[v] = 1;
        }
        int cnt = 0;
        for(auto it : validNodes){
            if(ds.findParent(it.first) == it.first) cnt++;
        }
        int ans = stones.size() - cnt;
        return ans;
    }
};