class Solution {
public:
    vector<int> psoe(vector<int>& arr){
        stack<int> st;
        vector<int> a(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) a[i] = -1;
            else a[i] = st.top();
            st.push(i);
        }
        return a;
    }
    vector<int> nse(vector<int>& arr){
        stack<int> st;
        vector<int> b(arr.size());
        for(int i = (int)arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) b[i] = arr.size();
            else b[i] = st.top();
            st.push(i);
        }
        return b;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long contri = 0;
        long long ans = 0;
        int mod = 1e9 + 7;
        vector<int> p_o_s_e = psoe(arr);
        vector<int> n_s_e = nse(arr);
        for(int i = 0; i < arr.size(); i++){
            contri = (1ll * (i - p_o_s_e[i]) * (n_s_e[i] - i)) % mod;
            ans = (ans + (1LL * arr[i] * contri) % mod) % mod;
        }
        return ans;
    }
};