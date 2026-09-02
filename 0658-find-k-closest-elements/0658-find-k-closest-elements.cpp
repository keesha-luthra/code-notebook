class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxh;
        for(int i = 0; i < arr.size(); i++){
            int d = abs(arr[i] - x);
            maxh.push({d, arr[i]});
            if(maxh.size() > k){
                maxh.pop();
            }
        }

        vector<int> ans;
        while(!maxh.empty()){
            int n = maxh.top().second;
            ans.push_back(n);
            maxh.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};