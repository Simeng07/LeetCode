class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        result = grid;
        if (k % (m * n) == 0) {
            return result;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int from = i * m + j;
                int to = (from + k) % (m * n);
                int toi = to / m;
                int toj = to % m;
                result[toi][toj] = grid[i][j];
            }
        }
        return result;
    }
};