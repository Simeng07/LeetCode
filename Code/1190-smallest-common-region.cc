class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> m;
        for (auto region : regions) {
            if (region.size() > 1) {
                for (int i = 1; i < region.size(); i++) {
                    m[region[i]] = region[0];
                }
            }
        }
        unordered_set<string> s;
        s.insert(region1);
        while (true) {
            if (m[region1] != "") {
                region1 = m[region1];
                s.insert(region1);
            } else {
                break;
            }
        }
        if (s.find(region2) != s.end()) {
            return region2;
        }
        while (true) {
            if (m[region2] != "") {
                region2 = m[region2];
                if (s.find(region2) != s.end()) {
                    return region2;
                }
            }
        }
        return "";
    }
};