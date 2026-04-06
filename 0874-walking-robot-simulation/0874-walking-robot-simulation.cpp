class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int d = 0; //north direction
        int maxDist = 0;

        vector<pair<int, int>> dirs = {
            {0,1},{1,0}, {0,-1}, {-1,0}};

        set<pair<int, int>> obs;
        for(auto &o : obstacles){
            obs.insert({o[0], o[1]});
        }

        for(int cmd : commands){
            if(cmd == -1)
                d = (d + 1) % 4;
            else if(cmd == -2)
                d = (d + 3) % 4;
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;
                    if(obs.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};