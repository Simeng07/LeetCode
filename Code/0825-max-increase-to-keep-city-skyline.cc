class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        
        // m行n列
        int row[m];
        memset(row, 0, sizeof(row));
        int column[n];
        memset(column, 0, sizeof(column));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                column[j] = max(column[j], grid[i][j]);
            }
        }
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result+= min(row[i], column[j]) - grid[i][j];
            }
        }
        
        return result;
    }
};