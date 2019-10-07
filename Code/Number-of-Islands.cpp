class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    result += 1;
                    helper(grid, i, j);
                }
            }
        }
        return result;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            if (i > 0) {
                helper(grid, i - 1, j);
            }
            if (j > 0) {
                helper(grid, i, j - 1);
            }
            if (i < grid.size() - 1) {
                helper(grid, i + 1, j);
            }
            if (j < grid[0].size() - 1) {
                helper(grid, i, j + 1);
            }
        }
    }
};