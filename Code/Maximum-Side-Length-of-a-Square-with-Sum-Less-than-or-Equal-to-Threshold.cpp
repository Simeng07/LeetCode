class Solution {
    int a[300][300] = {0};
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int length = 0;
        int m = mat.size();
        int n = mat[0].size();
        bool find = false;
        int result = 0;
        while (length <= m && length <= n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == INT_MAX) {
                        continue;
                    }
                    if (i + length >= m || j + length >= n) {
                        a[i][j] = INT_MAX;
                        continue;
                    }
                    for (int k = 0; k < length; k++) {
                        a[i][j] += mat[i + k][j + length];
                        a[i][j] += mat[i + length][j + k];
                    }
                    a[i][j] += mat[i + length][j + length];
                    if (a[i][j] > threshold) {
                        a[i][j] = INT_MAX;
                    } else {
                        find = true;
                        result = length + 1;
                    }
                }
            }
            if (!find) {
                break;
            }
            length++;
        }
        return result;
    }
};