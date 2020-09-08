class DinnerPlates {
    vector<stack<int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    int capacity;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        if (pq.empty() || pq.top() >= v.size()) {
            stack<int> stk;
            stk.push(val);
            v.push_back(stk);
            if (capacity != 1) {
                pq.push(v.size() - 1);
            }
        } else {
            int index = pq.top();
            v[index].push(val);
            if (v[index].size() == capacity) {
                pq.pop();
                // 有可能不排在前面的stack，由于pop了元素，导致不能装盘子了（自己被删了），但是还存在于pq中。这样下次再加进来的时候，会有两个同样的index
                while (!pq.empty() && pq.top() == index) {
                    pq.pop();
                }
            }
        }
    }
    
    int pop() {
        return popAtStack(v.size() - 1);
    }
    
    int popAtStack(int index) {
        if (v.size() <= index || v[index].empty()) {
            return -1;
        }
        int result = v[index].top();
        v[index].pop();
        if (capacity != 1 && v[index].size() == capacity - 1) {
            pq.push(index);
        }
        if (v[index].size() == 0 && index == v.size() - 1) {
            v.pop_back();
            int i = index - 1;
            while (i >= 0 && v[i].size() == 0) {
                v.pop_back();
                i--;
            }
        }
        return result;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */