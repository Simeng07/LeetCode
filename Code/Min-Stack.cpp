class MinStack {
    vector<int> v;
    vector<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        v.push_back(x);
        if (v.size() == 1) {
            mins.push_back(x);
        } else {
            mins.push_back(min(x, mins.back()));
        }
    }
    
    void pop() {
        if (!v.empty()) {
            v.pop_back();
            mins.pop_back();
        }
    }
    
    int top() {
        if (!v.empty()) {
            return v.back();
        }
        return 0;
    }
    
    int getMin() {
        return mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */