class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int pse = 0;
        int nse = 0;
        int width = 0;
        int height = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]) {
                height = heights[st.top()];
                st.pop();
                nse = i;
                if(st.empty()) pse = -1;
                else pse = st.top();
                width = nse - pse - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        if(maxi == INT_MIN) return 0;
        else return maxi;
    }
};