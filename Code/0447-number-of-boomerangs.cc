class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }
                int gapx = points[j].first - points[i].first;
                int gapy = points[j].second - points[i].second;
                int gap = gapx * gapx + gapy * gapy;
                m[gap]++;
            }
            for (auto& mm : m) {
                if (mm.second > 1) {
                    result += mm.second * (mm.second - 1);
                }
            }
        }
        return result;
    }
};