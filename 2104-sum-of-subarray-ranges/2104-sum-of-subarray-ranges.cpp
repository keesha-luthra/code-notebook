class Solution {
public:
    vector<int> nge1(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> a(n);
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) a[i] = nums.size();
            else a[i] = st.top();
            st.push(i);
        }
        return a;
    }
    vector<int> pge1(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> b(n);
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) b[i] = -1;
            else b[i] = st.top();
            st.push(i);
        }
        return b;
    }
    vector<int> nse1(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> c(n);
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) c[i] = nums.size();
            else c[i] = st.top();
            st.push(i);
        }
        return c;
    }
    vector<int> pse1(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> d(n);
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) d[i] = -1;
            else d[i] = st.top();
            st.push(i);
        }
        return d;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nge = nge1(nums);
        vector<int> pge = pge1(nums);
        vector<int> nse = nse1(nums);
        vector<int> pse = pse1(nums);
        long long sum_mini = 0;
        long long sum_maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            long long contri1 = (1LL * (i - pse[i]) * (nse[i] - i));
            sum_mini = sum_mini + (1LL * contri1 * nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            long long contri2 = (1LL * (i - pge[i]) * (nge[i] - i));
            sum_maxi = sum_maxi + (1LL * contri2 * nums[i]);
        }
        return sum_maxi - sum_mini;
    }
};