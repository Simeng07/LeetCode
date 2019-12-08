class Solution {
    int result = INT_MAX;
public:
    int minFlips(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size() * mat[0].size(); i++) {
            helper(mat, i, 0);
        }
        return (result == INT_MAX ? -1 : result);
    }
    void helper(vector<vector<int>> &mat, int index, int current) {
        int m = mat.size();
        int n = mat[0].size();
        int i = index / n;
        int j = index % n;
        if (index == m * n) {
            for (int ii = 0; ii < m; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (mat[ii][jj] == 1) {
                        return;
                    }
                }
            }
            result = min(result, current);
            return;
        }
        for (int ii = 0; ii < i; ii++) {
            for (int jj = 0; jj < j; jj++) {
                if (mat[ii][jj] == 1) {
                    return;
                }
            }
        }
        helper(mat, index + 1, current);
        changePatch(mat, i, j);
        helper(mat, index + 1, current + 1);
        changePatch(mat, i, j);
    }
    
    void changePatch(vector<vector<int>> &mat, int i, int j) {
        mat[i][j] ^= 1;
        if (i - 1 >= 0) {
            mat[i - 1][j] ^= 1;
        }
        if (j - 1 >= 0) {
            mat[i][j - 1] ^= 1;
        }
        if (i + 1 < mat.size()) {
            mat[i + 1][j] ^= 1;
        }
        if (j + 1 < mat[0].size()) {
            mat[i][j + 1] ^= 1;
        }
    }
};