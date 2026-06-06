class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); 
        int n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = m;
        int total_left = (m + n + 1) / 2;
        double res = 0;
        while(low <= high){
            int i = low + (high - low) / 2;
            int j = total_left - i;
            double leftA, leftB, rightA, rightB = 0;
            
            if(i == 0) leftA = INT_MIN;
            else leftA = nums1[i - 1];
            
            if(i == m) rightA = INT_MAX;
            else rightA = nums1[i];
            
            if(j == 0) leftB = INT_MIN;
            else leftB = nums2[j - 1];
            
            if(j == n) rightB = INT_MAX;
            else rightB = nums2[j];

            if(leftA > rightB) high = i - 1;

            else if(leftB > rightA) low = i + 1;

            else{
                if((m + n) % 2 != 0){
                    res = max(leftA, leftB);
                    return res;
                }
            
                else{
                    res = (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                    return res;
                }
            }
        }
        return 0;
    }
};
