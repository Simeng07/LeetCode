class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        int x = -1, y = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    if ((i == 0 && j == 0)
                       || (i == 0 && land[i][j - 1] != 2)
                       || (j == 0 && land[i - 1][j] != 2)
                       || (i != 0 && j != 0 && land[i - 1][j] != 2 && land[i][j - 1] != 2)) {
                        x = i; y = j;
                        bool find = false;
                        for (int ii = i; ii < m; ii++) {
                            for (int jj = j; jj < n; jj++) {
                                if (land[ii][jj] != 1) {
                                    break;
                                }
                                if ((ii == m - 1 && jj == n - 1)
                                    || (ii == m - 1 && land[ii][jj + 1] != 1)
                                    || (jj == n - 1 && land[ii + 1][jj] != 1)
                                    || (ii != m - 1 && jj != n - 1 && land[ii + 1][jj] != 1 && land[ii][jj + 1] != 1)) {
                                    result.push_back({x, y, ii, jj});
                                    find = true;
                                }
                            }
                            if (land[ii][j] != 1) {
                                break;
                            }
                        }
                        if (!find) {
                            result.push_back({x, y, x, y});
                        }
                        
                    }
                    land[i][j] = 2;
                }
            }
        }
        return result;
    }
};