class Solution {
    int color = 2;
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    paint(grid, i, j, color);
                    color++;
                    if (color != 3) {
                        // more than one island
                        return 0;
                    }
                }
            }
        }
        
        // delete one cell and see how it works
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == color - 1) {
                    grid[i][j] = 0;
                    if (isDisconected(grid, i, j)) {
                        return 1;
                    }
                    grid[i][j] = color - 1;
                }
            }
        }
        
        // otherwise... 2
        return 2;
    }
    
    void paint(vector<vector<int>>& grid, int i, int j, int color) {
        int oldColor = grid[i][j];
        grid[i][j] = color;
        if (i - 1 >= 0 && grid[i - 1][j] == oldColor) {
            paint(grid, i - 1, j, color);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == oldColor) {
            paint(grid, i + 1, j, color);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == oldColor) {
            paint(grid, i, j - 1, color);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == oldColor) {
            paint(grid, i, j + 1, color);
        }
    }
    
    bool isDisconected(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        int oldColor = color;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == oldColor - 1) {
                    paint(grid, i, j, color);
                    color++;
                    if (color != oldColor + 1) {
                        // more than one island
                        return true;
                    }
                }
            }
        }
        
        if (color == oldColor) {
            // no island at all
            return true;
        }
        
        return false;
    }
};