// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int d = 0;
//         int j = 0;
//         for(int i = 0; i < nums1.size(); i++){
//             for(j = i; j < nums2.size(); j++){
//                 if(nums1[i] <= nums2[j]){
//                     d = max(d, j - i);
//                 }
//                 else break;
//             }
//         }
//         return d;
//     }
// };
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;  // try to increase distance
            } else {
                i++;  // need a smaller nums1[i]
            }
        }

        return ans;
    }
};