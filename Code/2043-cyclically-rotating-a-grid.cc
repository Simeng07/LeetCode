class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int gap = min(min(i, m - 1 - i), min(j, n - 1 - j));
                int count = 2 * m + 2 * n - 4 - 8 * gap;
                int localk = k % count;
                int leftmost = gap, rightmost = n - 1 - gap, topmost = gap, bottommost = m - 1 - gap;
                int locali = i, localj = j;
                while (localk > 0) {
                    if (locali == topmost) {
                        if (localj == leftmost) {
                            locali++;
                        } else {
                            localj--;
                        }
                    } else if (locali == bottommost) {
                        if (localj == rightmost) {
                            locali--;
                        } else {
                            localj++;
                        }
                    } else {
                        if (localj == leftmost) {
                            locali++;
                        } else {
                            locali--;
                        }
                    }
                    localk--;
                }
                result[locali][localj] = grid[i][j];
            }
        }
        return result;
    }
};