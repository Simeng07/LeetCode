class Solution {
    int colorCount[1250] = {0};
    int result = 0;
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int color = 2;
        int size = grid.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 1) {
                    change(grid, i, j, color);
                    color++;
                }
            }
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 0) {
                    check(grid, i, j);
                }
            }
        }
        
        for (int i = 0; i < 1250; i++) {
            result = max(result, colorCount[i]);
        }
        
        return result;
    }
    
    void change(vector<vector<int>>& grid, int i, int j, int color) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size()) {
            return;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = color;
            colorCount[color]++;
            change(grid, i - 1, j, color);
            change(grid, i, j - 1, color);
            change(grid, i + 1, j, color);
            change(grid, i, j + 1, color);
        }
    }
    
    void check(vector<vector<int>>& grid, int i, int j) {
        int topCount = 0, leftCount = 0, rightCount = 0, bottomCount = 0;
        int topColor = 0, leftColor = 0, rightColor = 0, bottomColor = 0;
        // Em... Set is slower.
        // unordered_set<int> has;
        if (i - 1 >= 0) {
            leftColor = grid[i - 1][j];
            leftCount = colorCount[leftColor];
        }
        if (j - 1 >= 0) {
            topColor = grid[i][j - 1];
            if (topColor != leftColor) {
                topCount = colorCount[topColor];
            }
        }
        if (i + 1 < grid.size()) {
            rightColor = grid[i + 1][j];
            if (rightColor != leftColor && rightColor != topColor) {
                rightCount = colorCount[rightColor];
            }
        }
        if (j + 1 < grid.size()) {
            bottomColor = grid[i][j + 1];
            if (bottomColor != leftColor && bottomColor != topColor && bottomColor != rightColor) {
                bottomCount = colorCount[bottomColor];
            }
        }
        
        result = max(result, leftCount + topCount + rightCount + bottomCount + 1);
    }
};