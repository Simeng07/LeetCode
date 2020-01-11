class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        int last = 0;
        for (int i = 0; i <= min(K, m - 1); i++) {
            for (int j = 0; j <= min(K, n - 1); j++) {
                last += mat[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    result[i][j] = last;
                    continue;
                }
                cout << i << " " << j << endl;
                if (j == 0) {
                    last = result[i - 1][0];
                    for (int jj = max(0, j - K); jj <= min(j + K, n - 1); jj++) {
                        if (i + K < m) {
                            last += mat[i + K][jj];
                        }
                        if (i - K - 1 >= 0) {
                            last -= mat[i - K - 1][jj];
                        }
                    }
                } else {
                    for (int ii = max(0, i - K); ii <= min(i + K, m - 1); ii++) {
                        if (j + K < n) {
                            last += mat[ii][j + K];
                        }
                        if (j - K - 1 >= 0) {
                            last -= mat[ii][j - K - 1];
                        }
                    }
                }
                result[i][j] = last;
            }
        }
        
        return result;
    }
};