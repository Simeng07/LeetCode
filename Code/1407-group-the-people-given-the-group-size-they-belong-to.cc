class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].insert(i);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            auto sit = (it->second).begin();
            int total = (it->second).size();
            int patch = (total / it->first);
            for (int i = 0; i < patch; i++) {
                vector<int> tmp;
                for (int i = 0; i < it->first; i++) {
                    tmp.push_back(*sit);
                    sit++;
                }
                result.push_back(tmp);
            }
        }
        return result;
    }
};