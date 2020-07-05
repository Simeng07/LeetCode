class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                int length = n - j;
                for (int ii = 0; ii + i < m; ii++) {
                    if (length == 0) {
                        break;
                    }
                    for (int jj = 0; jj < length; jj++) {
                        if (mat[i + ii][j + jj] == 0) {
                            length = jj;
                        } else {
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};