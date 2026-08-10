class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() { 
    }
    
    void push(int value) {
        int minVal=INT_MAX;
        if(!st.empty()) minVal=st.top().second;
        minVal=min(minVal,value);
        st.push({value, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.empty()?0:st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */