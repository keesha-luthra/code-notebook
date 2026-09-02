class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        // Change to a Min-Heap: pair<frequency, element>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        
        for(auto it : mpp){
            minh.push({it.second, it.first});
            
            // If size exceeds k, pop the smallest frequency element
            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<int> ans;
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        
        return ans;
    }
};