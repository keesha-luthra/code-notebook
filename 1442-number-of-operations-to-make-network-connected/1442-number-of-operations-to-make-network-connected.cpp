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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            int parU = ds.findParent(u);
            int parV = ds.findParent(v);
            if(parU == parV) extraEdges++;
            else ds.unionBySize(u, v);
        }
        int cmp = 0;
        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i) cmp++;
        }
        if(extraEdges >= cmp - 1) return cmp - 1;
        else return -1;
    }
};