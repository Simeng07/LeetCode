class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> next(n, INT_MAX); // the index is the date
        unordered_map<int, int> position; // the key is the lake name, the value is the date
        for (int i = n - 1; i >= 0; i--) {
            if (rains[i] != 0) {
                if (position.find(rains[i]) != position.end()) {
                    next[i] = position[rains[i]];
                }
                position[rains[i]] = i;
            }
        }
        
        set<pair<int, int>> s;
        vector<int> result(n, -1);
        unordered_set<int> full;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (full.find(rains[i]) != full.end()) {
                    vector<int> r;
                    return r;
                }
                full.insert(rains[i]);
                s.insert(make_pair(next[i], rains[i]));
            } else {
                if (s.empty()) {
                    result[i] = 1;
                } else {
                    auto it = s.begin();
                    result[i] = it->second;
                    full.erase(it->second);
                    s.erase(it);
                }
            }
        }
        return result;
    }
};