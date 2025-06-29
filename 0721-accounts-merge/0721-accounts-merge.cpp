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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailToNode.find(mail) == mailToNode.end()){
                    mailToNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }
        vector<vector<string>> v(n);
        for(auto it : mailToNode){
            string m = it.first;
            int node = it.second;
            int p_node = ds.findParent(node);
            v[p_node].push_back(m);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(!v[i].empty()){
                vector<string> temp;
                temp.push_back(accounts[mailToNode[v[i][0]]][0]);
                sort(v[i].begin(), v[i].end());
                for(auto it : v[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
            else
                continue;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};