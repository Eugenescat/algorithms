class MinStack {
public:
    stack<int> stk, f;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (f.empty() || f.top() >= val) f.push(val);
    }
    
    void pop() {
        if (stk.top() <= f.top()) f.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return f.top();
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