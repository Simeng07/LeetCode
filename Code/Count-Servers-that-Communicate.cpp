class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mhas[250] = {0};
        int nhas[250] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mhas[i]++;
                    nhas[j]++;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (mhas[i] > 1 || nhas[j] > 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};