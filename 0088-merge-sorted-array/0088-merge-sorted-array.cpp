class Solution {
public:
    void swap1(vector<int>& nums1, int index1,
               vector<int>& nums2, int index2) {
        if(nums1[index1] > nums2[index2]) {
            swap(nums1[index1], nums2[index2]);
        }
    }

    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int len = m + n;
        int gap = len / 2 + len % 2;

        while(gap > 0) {

            int left = 0;
            int right = left + gap;

            while(right < len) {

                // Both elements are in nums1
                if(left < m && right < m) {
                    if(nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }

                // left in nums1, right in nums2
                else if(left < m && right >= m) {
                    swap1(nums1, left,
                          nums2, right - m);
                }

                // Both elements are in nums2
                else {
                    if(nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m],
                             nums2[right - m]);
                    }
                }

                left++;
                right++;
            }

            if(gap == 1)
                break;

            gap = gap / 2 + gap % 2;
        }

        // Copy sorted nums2 into nums1
        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};