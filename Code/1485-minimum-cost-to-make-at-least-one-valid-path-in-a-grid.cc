class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<vector<int>> dq;
        unordered_set<int> s;
        int result = 0;
        dq.push_back({0, 0});
        s.insert(0);
        while (!dq.empty()) {
            vector<int> &v = dq.front();
            int i = v[0] / 100;
            int j = v[0] % 100;
            int change = v[1];
            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                return change;
            }
            dq.pop_front();
            s.insert(i * 100 + j);
            if (j + 1 < grid[0].size() && s.find(i * 100 + j + 1) == s.end()) {
                if (grid[i][j] == 1) {
                    dq.push_front({i * 100 + j + 1, change});
                } else {
                    dq.push_back({i * 100 + j + 1, change + 1});
                }
            }
            if (j - 1 >= 0 && s.find(i * 100 + j - 1) == s.end()) {
                if (grid[i][j] == 2) {
                    dq.push_front({i * 100 + j - 1, change});
                } else {
                    dq.push_back({i * 100 + j - 1, change + 1});
                }
            }
            if (i + 1 < grid.size() && s.find((i + 1) * 100 + j) == s.end()) {
                if (grid[i][j] == 3) {
                    dq.push_front({(i + 1) * 100 + j, change});
                } else {
                    dq.push_back({(i + 1) * 100 + j, change + 1});
                }
            }
            if (i - 1 >= 0 && s.find((i - 1) * 100 + j) == s.end()) {
                if (grid[i][j] == 4) {
                    dq.push_front({(i - 1) * 100 + j, change});
                } else {
                    dq.push_back({(i - 1) * 100 + j, change + 1});
                }
            }
        }
        return 0;
    }
};