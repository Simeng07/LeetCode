class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for (auto &edge : edges) {
            m[edge[0]]++;
            m[edge[1]]++;
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == edges.size()) {
                return it->first;
            }
        }
        return 0;
    }
};