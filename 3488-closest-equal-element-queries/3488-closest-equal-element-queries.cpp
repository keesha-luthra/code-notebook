// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         vector<int> ans;
//         int minDistance = INT_MAX;
//         int idx, target;
//         for(int i = 0; i < queries.size(); i++){
//             idx = queries[i];
//             target = nums[idx];
//             for(int j = 0; j < nums.size(); j++){
//                 if(nums[j] == target && j != idx){
//                     int left = abs(idx - j);
//                     int right = nums.size() - left;
//                     minDistance = min(minDistance, min(left, right));
//                 }
//             }
//             if(minDistance != INT_MAX){
//                 ans.push_back(minDistance);
//                 minDistance = INT_MAX;
//             }
//             else
//                 ans.push_back(-1);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: Map value -> all indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        // Step 2: Process each query
        for (int idx : queries) {
            int target = nums[idx];
            vector<int>& positions = mp[target];

            // If only one occurrence → no other equal element
            if (positions.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Step 3: Find position using binary search
            auto it = lower_bound(positions.begin(), positions.end(), idx);
            int pos = it - positions.begin();

            // Step 4: Get neighbors (circular)
            int leftIdx = (pos == 0) ? positions.back() : positions[pos - 1];
            int rightIdx = (pos == positions.size() - 1) ? positions[0] : positions[pos + 1];

            // Step 5: Compute circular distances
            int d1 = abs(idx - leftIdx);
            int d2 = abs(idx - rightIdx);

            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};