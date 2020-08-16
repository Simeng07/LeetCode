class Solution {
    int color = 2;
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxBorder = -1;
        int maxProtect = -1;
        int maxLocation = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    paint(grid, i, j, color);
                    pair<int, int> border = count(grid, color);
                    color++;
                    if (border.first > maxProtect) {
                        maxProtect = border.first;
                        maxBorder = border.second;
                        maxLocation = i * 50 + j;
                    }
                }
            }
        }
        if (maxLocation == -1) {
            return 0;
        }
        
        int result = 0;
        while (maxProtect != -1) {
            result += maxBorder;
            maxBorder = -1;
            maxProtect = -1;
            paint(grid, maxLocation / 50, maxLocation % 50, -1);
            int currentColor = color;
            color++;
            unordered_set<int> has;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != 0 && grid[i][j] != -1 && grid[i][j] <= currentColor && has.find(grid[i][j]) == has.end()) {
                        has.insert(grid[i][j]);
                        spread(grid, grid[i][j]);
                    }
                }
            }
            
            currentColor = color;
            color++;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != 0 && grid[i][j] != -1 && grid[i][j] <= currentColor) {
                        paint(grid, i, j, color);
                        pair<int, int> border = count(grid, color);
                        color++;
                        if (border.first > maxProtect) {
                            maxProtect = border.first;
                            maxBorder = border.second;
                            maxLocation = i * 50 + j;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    void paint(vector<vector<int>>& grid, int i, int j, int color) {
        if (grid[i][j] == color) {
            return;
        }
        grid[i][j] = color;
        if (i - 1 >= 0 && grid[i - 1][j] > 0) {
            paint(grid, i - 1, j, color);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] > 0) {
            paint(grid, i + 1, j, color);
        }
        if (j - 1 >= 0 && grid[i][j - 1] > 0) {
            paint(grid, i, j - 1, color);
        }
        if (j + 1 <grid[0].size() && grid[i][j + 1] > 0) {
            paint(grid, i, j + 1, color);
        }
    }
    
    void spread(vector<vector<int>>& grid, int color) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == color) {
                    if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                        grid[i - 1][j] = this->color;
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0) {
                        grid[i + 1][j] = this->color;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                        grid[i][j - 1] = this->color;
                    }
                    if (j + 1 < grid[0].size() && grid[i][j + 1] == 0) {
                        grid[i][j + 1] = this->color;
                    }
                }
            }
        }
    }
    
    pair<int, int> count(vector<vector<int>>& grid, int color) {
        unordered_set<int> s;
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == color) {
                    if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                        s.insert((i - 1) * 50 + j);
                        num++;
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == 0) {
                        s.insert((i + 1) * 50 + j);
                        num++;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                        s.insert(i * 50 + j - 1);
                        num++;
                    }
                    if (j + 1 < grid[0].size() && grid[i][j + 1] == 0) {
                        s.insert(i * 50 + j + 1);
                        num++;
                    }
                }
            }
        }
        return make_pair(s.size(), num);
    }
    
    void print(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << grid[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};