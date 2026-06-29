class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& isConnected, int n) {
        visited[node] = 1;
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, visited, isConnected, n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        vector<int> visited(m, 0);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected, n);
                cnt++;
            }
        }
        return cnt;
    }
};