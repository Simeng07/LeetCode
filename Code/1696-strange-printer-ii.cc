class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int, vector<int>> m; // minx, miny, maxx, maxy
        for (int i = 0; i < targetGrid.size(); i++) {
            for (int j = 0; j < targetGrid[0].size(); j++) {
                int color = targetGrid[i][j];
                if (m.find(color) == m.end()) {
                    m[color] = {i, j, i, j};
                } else {
                    auto &frame = m[color];
                    m[color] = {min(i, frame[0]), min(j, frame[1]), max(i, frame[2]), max(j, frame[3])};
                }
            }
        }
        
        bool hasChange = true;
        bool needChange = false;
        unordered_set<int> done;
        
        while (hasChange) {
            hasChange = false;
            needChange = false;
            for (auto it = m.begin(); it != m.end(); ++it) {
                int color = it->first;
                if (done.find(color) != done.end()) {
                    continue;
                }
                auto &frame = it->second;
                bool flag = true;
                for (int i = frame[0]; flag && i <= frame[2]; i++) {
                    for (int j = frame[1]; j <= frame[3]; j++) {
                        if (targetGrid[i][j] != color && targetGrid[i][j] != -1) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    for (int i = frame[0]; flag && i <= frame[2]; i++) {
                        for (int j = frame[1]; j <= frame[3]; j++) {
                            targetGrid[i][j] = -1;
                        }
                    }
                    done.insert(color);
                    hasChange = true;
                } else {
                    needChange = true;
                }
            }
        }
        
        return !needChange;
    }
};