class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_seen = -1;
        int n = arr.size();
        vector<int> result(n, 0);
        for(int i = arr.size() - 1; i >= 0; i--){
            result[i] = max_seen;
            if(arr[i] > max_seen){
                max_seen = arr[i];
            }
        }
        return result;
    }
};