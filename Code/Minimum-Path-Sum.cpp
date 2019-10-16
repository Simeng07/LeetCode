class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v(n, 0);
        for (int i = 0; i < m; i++) {
            v[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                if (i == 0) {
                    v[j] = grid[i][j] + v[j - 1];
                } else {
                    v[j] = grid[i][j] + min(v[j], v[j - 1]);
                }
            }
        }
        return v[n - 1];
    }
};