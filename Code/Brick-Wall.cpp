class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.size() == 0) {
            return 0;
        }
        if (wall.size() == 1) {
            if (wall[0].size() == 1) {
                return 1;
            } else {
                return 0;
            }
        }
        unordered_map<int, int> m;
        int rowSize = 0;
        for (auto &row : wall) {
            int size = 0;
            for (auto &brick : row) {
                size += brick;
                m[size]++;
            }
            if (rowSize == 0) {
                rowSize = size;
            }
        }
        int crack = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first != rowSize) {
                crack = max(crack, it->second);
            }
        }
        return wall.size() - crack;
    }
};