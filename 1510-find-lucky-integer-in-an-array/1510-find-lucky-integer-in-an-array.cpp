class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        int lucky = -1;
        for(auto it : mpp){
            if(it.first == it.second) lucky = it.first;
        }
        return lucky;
    }
};