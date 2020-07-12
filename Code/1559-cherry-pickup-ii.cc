class Solution {
    int dp[70][70][70];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, grid[0].size() - 1);
    }
    int helper(vector<vector<int>>& grid, int i, int j1, int j2) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return 0;
        }
        if (dp[i][j1][j2] > 0) {
            return dp[i][j1][j2];
        }
        int current = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
        if (i == m - 1) {
            return current;
        }
        int result = 0;
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                result = max(result, helper(grid, i + 1, j1 + a, j2 + b));
            }
        }
        dp[i][j1][j2] = result + current;
        return dp[i][j1][j2];
    }
};