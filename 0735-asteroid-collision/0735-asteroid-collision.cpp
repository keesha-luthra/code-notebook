class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto a : asteroids){
            while(!st.empty() && st.top() > 0 && a < 0 && st.top() < -a) st.pop();
            if(!st.empty() && st.top() > 0 && a < 0){
                if(st.top() == -a) st.pop();
            }
            else st.push(a);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};