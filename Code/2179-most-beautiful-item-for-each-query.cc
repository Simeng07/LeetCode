class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> m;
        int cMax = INT_MIN;
        for (auto &item : items) {
            cMax = max(cMax, item[1]);
            m[item[0]] = cMax;
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            auto it = m.upper_bound(queries[i]);
            if (it != m.begin()) {
                --it;
                result[i] = it->second;
            }
        }
        return result;
    }
};