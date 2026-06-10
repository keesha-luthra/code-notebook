class Solution {
public:
    int helper(vector<int> heights){
        stack<int> st;
        heights.push_back(0);
        int nse = 0;
        int pse = 0;
        int width = 0;
        int h = 0;
        int area = 0;
        int curr = 0;
        int res = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            curr = heights[i];
            while(!st.empty() && heights[st.top()] > curr){
                h = heights[st.top()];
                nse = i;
                st.pop();
                if(st.empty()) pse = -1;
                else pse = st.top();
                width = nse - pse - 1;
                area = width * h;
                res = max(res, area);
            }
            st.push(i);
        }
        if(res == INT_MIN) return 0;
        else return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, helper(heights));
        }
        return ans;
    }
};