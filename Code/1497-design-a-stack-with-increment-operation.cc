class CustomStack {
    // alloc constant space and use a param to indicate the real valid size should be better
    vector<int> v;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (v.size() == maxSize) {
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if (v.size() == 0) {
            return -1;
        }
        int result = v.back();
        v.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)v.size()); i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */