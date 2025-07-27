class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> answer(n, -1);
        // stack<int> st;

        // for (int i = 2 * n - 1; i >= 0; i--) {
        //     int current = nums[i % n];

        //     while (!st.empty() && st.top() <= current) {
        //         st.pop();
        //     }

        //     if (i < n) {
        //         if (!st.empty()) {
        //             answer[i] = st.top();
        //         }
        //     }

        //     st.push(current);
        // }

        // return answer;
        vector<int> answer;
        int n = nums.size();
        stack<int> st;
        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if(i < n){
                if(st.empty()) answer.push_back(-1);
                else {
                    answer.push_back(st.top());
                }
            }
            st.push(nums[i % n]);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
