class RangeModule {
    vector<pair<int, int>> v;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        pair<int, int> p = make_pair(left, right);
        auto it = lower_bound(v.begin(), v.end(), p);
        auto index = it - v.begin();
        // left
        if (index != 0) {
            int last = index - 1;
            if (v[last].second >= left) {
                v[last].second = max(v[last].second, right);
                index = last;
            } else {
                v.insert(v.begin() + index, p);
            }
        } else {
            v.insert(v.begin() + index, p);
        }
        // right
        int r = index + 1;
        while (r < v.size() && v[r].first <= right) {
            v[index].second = max(v[index].second, v[r].second);
            v.erase(v.begin() + r);
        }
    }
    
    bool queryRange(int left, int right) {
        if (v.size() == 0) {
            return false;
        }
        auto it = lower_bound(v.begin(), v.end(), make_pair(left, right));
        if (it == v.end()) {
            --it;
        }
        if (it->first <= left && it->second >= right) {
            return true;
        }
        if (it != v.begin()) {
            --it;
            if (it->first <= left && it->second >= right) {
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = lower_bound(v.begin(), v.end(), make_pair(left, left + 1));
        if (it != v.begin()) {
            --it;
        }
        int index = it - v.begin();
        while (index < v.size() && v[index].first <= right) {
            if (v[index].second <= left) {
                index++;
                continue;
            } else {
                if (left < v[index].first) {
                    if (right >= v[index].second) {
                        v.erase(v.begin() + index);
                    } else {
                        v[index].first = right;
                        break;
                    }
                } else {
                    if (v[index].second > right) {
                        // hole
                        v.insert(v.begin() + index + 1, make_pair(right, v[index].second));
                    }
                    v[index].second = left;
                    index++;
                }
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */