class MinStack {
private:
// stack store two values, first is the current value and the second is the minimum seen so far
stack <pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else{
            // here st.top().second is the minimum seen so far
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */