class Solution {
public:
    vector<int> prefixMax(vector<int>& height){
        vector<int> pMax(height.size());
        pMax[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            pMax[i] = max(height[i], pMax[i - 1]);
        }
        return pMax;
    }
    vector<int> suffixMax(vector<int>& height){
        vector<int> sMax(height.size());
        sMax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            sMax[i] = max(height[i], sMax[i + 1]);
        }
        return sMax;
    }
    int trap(vector<int>& height) {
        // int leftMax = INT_MIN;
        // int rightMax = INT_MIN;
        // int l = 0;
        // int r = height.size() - 1;
        // int ans = 0;
        // while(l < r){
        //     if(height[l] <= height[r]){
        //         if(height[l] > leftMax){
        //             leftMax = height[l];
        //         }
        //         else ans += leftMax - height[l];
        //         l++;
        //     }
        //     else if(height[r] < height[l]){
        //         if(height[r] > rightMax){
        //             rightMax = height[r];
        //         }
        //         else ans += rightMax - height[r];
        //         r--;
        //     }
        // }
        // return ans;
        int ans = 0;
        vector<int> prefix_Max = prefixMax(height);
        vector<int> suffix_Max = suffixMax(height);
        for(int i = 0; i < height.size(); i++){
            ans = ans + (min(prefix_Max[i], suffix_Max[i]) - height[i]);
        }
        return ans;
    }
};