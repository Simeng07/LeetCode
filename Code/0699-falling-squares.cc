class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<pair<int, int>, int> m;
        m[{0, 1000000000}] = 0;
        vector<int> result;
        int highestHeight = 0;
        for (auto &position : positions) {
            vector<vector<int>> toAdd; // save modified ones
            int start = position[0];
            int length = position[1];
            int end = start + length;
            int height = 0;
            auto it = m.lower_bound({start, 0});
            if (it != m.begin()) {
                --it; // left one
                if (it->first.second <= start) {
                    ++it;
                }
            }
            while (it != m.end() && it->first.first < end) { // cross
                if (start > it->first.first) {
                    toAdd.push_back({it->first.first, start, it->second});
                }
                if (end < it->first.second) {
                    toAdd.push_back({end, it->first.second, it->second});
                }
                height = max(height, it->second);
                it = m.erase(it); // return the next iterator
            }
            m[{start, end}] = height + length;
            for (auto &t : toAdd) {
                m[{t[0], t[1]}] = t[2];
            }
            highestHeight = max(highestHeight, height + length);
            result.push_back(highestHeight);
        }
        return result;
    }
};