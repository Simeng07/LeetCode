class Solution {
    unordered_set<int> has;
    int m, n;
    bool find = false;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (m == 1 && n == 1) {
            return true;
        }
        has.insert(0);
        switch (grid[0][0]) {
            case 1:
            case 6:
                helper(grid, 0, 1, 0, 0);
                break;
            case 2:
            case 3:
                helper(grid, 1, 0, 0, 0);
                break;
            case 4:
                helper(grid, 0, 1, 0, 0);
                helper(grid, 1, 0, 0, 0);
                break;
            case 5:
                return false;
            default:
                break;
        }
        return find;
    }
    
    void helper(vector<vector<int>>& grid, int i, int j, int lasti, int lastj) {
        if (find) {
            return;
        }
        if (i == m - 1 && j == n - 1) {
            switch (grid[i][j]) {
                case 1:
                case 3:
                    if (i == lasti && j == lastj + 1) {
                        find = true;
                    }
                    break;
                case 2:
                case 6:
                    if (i == lasti + 1 && j == lastj) {
                        find = true;
                    }
                    break;
                case 5:
                    if ((i == lasti + 1 && j == lastj) || (i == lasti && j == lastj + 1)) {
                        find = true;
                    }
                    break;
                default:
                    break;
            }
            return;
        }
        if (i >= m || j >= n || i < 0 || j < 0) {
            return;
        }
        int hash = i * 300 + j;
        if (has.find(hash) != has.end()) {
            return;
        } else {
            has.insert(hash);
        }
        switch (grid[i][j]) {
            case 1:
                if (i == lasti) {
                    helper(grid, i, j == lastj + 1 ? j + 1 : j - 1, i, j);
                    break;
                } else {
                    return;
                }
            case 2:
                if (j == lastj) {
                    helper(grid, i == lasti + 1 ? i + 1 : i - 1, j, i, j);
                    break;
                } else {
                    return;
                }
            case 3:
                if (i == lasti && j == lastj + 1) {
                    helper(grid, i + 1, j, i, j);
                    break;
                } else if (i == lasti - 1 && j == lastj) {
                    helper(grid, i, j - 1, i, j);
                    break;
                } else {
                    return;
                }
            case 4:
                if (i == lasti && j == lastj - 1) {
                    helper(grid, i + 1, j, i, j);
                    break;
                } else if (i == lasti - 1 && j == lastj) {
                    helper(grid, i, j + 1, i, j);
                    break;
                } else {
                    return;
                }
            case 5:
                if (i == lasti && j == lastj + 1) {
                    helper(grid, i - 1, j, i, j);
                    break;
                } else if (i == lasti + 1 && j == lastj) {
                    helper(grid, i, j - 1, i, j);
                    break;
                } else {
                    return;
                }
            case 6:
                if (i == lasti && j == lastj - 1) {
                    helper(grid, i - 1, j, i, j);
                    break;
                } else if (i == lasti + 1 && j == lastj) {
                    helper(grid, i, j + 1, i, j);
                    break;
                } else {
                    return;
                }
            default:
                break;
        }
    }
};