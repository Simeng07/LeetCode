class Solution {
    int m;
    int n;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (m <= 1 || n <= 1) {
            return false;
        }
        vector<vector<bool>> has(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!has[i][j]) {
                    bool result = helper(grid, i, j, -1, -1, has);
                    if (result) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& grid, int i, int j, int lasti, int lastj, vector<vector<bool>> &has) {
        if (has[i][j]) {
            return true;
        }
        has[i][j] = true;
        char c = grid[i][j];
        bool result = false;
        if (i - 1 >= 0 && grid[i - 1][j] == c && (i - 1 != lasti || j != lastj)) {
            result = helper(grid, i - 1, j, i, j, has);
        }
        if (!result && i + 1 < m && grid[i + 1][j] == c && (i + 1 != lasti || j != lastj)) {
            result = helper(grid, i + 1, j, i, j, has);
        }
        if (!result && j - 1 >= 0 && grid[i][j - 1] == c && (i != lasti || j - 1 != lastj)) {
            result = helper(grid, i, j - 1, i, j, has);
        }
        if (!result && j + 1 < n && grid[i][j + 1] == c && (i != lasti || j + 1 != lastj)) {
            result = helper(grid, i, j + 1, i, j, has);
        }
        return result;
    }
};