class SummaryRanges {
    vector<vector<int> > v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (v.size() == 0) {
            v.push_back({val, val});
            return;
        }
        
        int bigger = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i][0] > val) {
                bigger = i;
                break;
            }
        }
        
        if (bigger == -1) {
            int n = v.size();
            if (v[n - 1][1] >= val) {
                // do nothing
            } else if (v[n - 1][1] + 1 == val) {
                v[n - 1] = {v[n - 1][0], val};
            } else {
                v.push_back({val, val});
            }
        } else if (bigger == 0) {
            if (v[0][0] == val + 1) {
                v[0] = {val, v[0][1]};
            } else {
                v.insert(v.begin(), {val, val});
            }
        } else {
            int smaller = bigger - 1;
            if (v[smaller][1] >= val) {
                // do nothing
            } else {
                if (v[smaller][1] + 1 == val) {
                    if (val + 1 == v[bigger][0]) {
                        v[smaller] = {v[smaller][0], v[bigger][1]};
                        v.erase(v.begin() + bigger);
                    } else {
                        v[smaller] = {v[smaller][0], val};
                    }
                } else if (val + 1 == v[bigger][0]) {
                    v[bigger] = {val, v[bigger][1]};
                } else {
                    v.insert(v.begin() + bigger, {val, val});
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */