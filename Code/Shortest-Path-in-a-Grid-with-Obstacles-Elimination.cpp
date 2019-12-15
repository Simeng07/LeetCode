class Solution {
    int a[40][40][1601];
    queue<vector<int>> current;
    bool answer = false;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }
        if (k >= m + n - 2) {
            return m + n - 2;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int kk = 0; kk <= k; kk++) {
                    a[i][j][kk] = INT_MAX;
                }
            }
        }
        int result = 0;
        current.push({0, 0, 0});
        a[0][0][0] = 0;
        int count = current.size();
        while (true) {
            result++;
            if (result > m * n || count == 0) {
                return -1;
            }
            while (count--) {
                auto &p = current.front();
                int i = p[0];
                int j = p[1];
                if (i - 1 >= 0) {
                    helper(grid, i - 1, j, k, p[2], result);
                }
                if (i + 1 < m) {
                    helper(grid, i + 1, j, k, p[2], result);
                }
                if (j - 1 >= 0) {
                    helper(grid, i, j - 1, k, p[2], result);
                }
                if (j + 1 < n) {
                    helper(grid, i, j + 1, k, p[2], result);
                }
                current.pop();
                if (answer) {
                    return result;
                }
            }
            count = current.size();
        }
        return result;
    }
    
    void helper(vector<vector<int>>& grid, int i, int j, int k, int currentk, int currents) {
        if (answer) {
            return;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            answer = true;
            return;
        }
        // cout << i << " " << j << endl;
        if (grid[i][j] == 0 || currentk < k) {
            if (grid[i][j] == 1) {
                currentk++;
            }
            bool find = false;
            for (int kk = 0; kk <= k; kk++) {
                if (a[i][j][kk] != INT_MAX && kk <= currentk) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                a[i][j][currentk] = min(a[i][j][currentk], currents + 1);
                current.push({i, j, currentk});
                // cout << i << " " << j << " " << currentk << " " << currents << endl;
            }
        }
    }
};