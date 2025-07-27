class Solution {
private:
vector<int> prefix(vector<int>& height, int n){
    vector<int> prefixMax(n, -1);
    prefixMax[0] = height[0];
    for(int i = 1; i < n; i++){
        prefixMax[i] = max(height[i], prefixMax[i - 1]);
    }
    return prefixMax;
}

vector<int> suffix(vector<int>& height, int n){
    vector<int> suffixMax(n, -1);
    suffixMax[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffixMax[i] = max(height[i], suffixMax[i + 1]);
    }
    return suffixMax;
}

public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> prefixMax = prefix(height, n);
        vector<int> suffixMax = suffix(height, n);
        for(int i = 0; i < n; i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            ans = ans + abs(height[i] - (min(leftMax, rightMax)));
        }
        return ans;
    }
};