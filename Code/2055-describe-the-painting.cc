class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> m;
        for (auto &segment : segments) {
            m[segment[0]] += (long long)segment[2];
            m[segment[1]] -= (long long)segment[2];
        }
        pair color = {0, 0}; // color, position
        vector<vector<long long>> result;
        auto left = m.begin();
        auto right = ++m.begin();
        long long current = left->second;
        while (right != m.end()) {
            if (current != 0)
                result.push_back({left->first, right->first, current});
            current += right->second;
            ++left;
            ++right;
        }
        return result;
    }
};