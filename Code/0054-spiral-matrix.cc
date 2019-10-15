class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        if (n == 0) return result;
    
        int cnt = 0;
        int i = 0;
        int j = 0;
        int circle = 0;
        while (cnt < m * n) {
            cnt++;
            result.push_back(matrix[i][j]);
            if (i == circle) {
                if (j == n - circle - 1) {
                    i++;
                    continue;
                }
                j++;
                continue;
            }
            if (j == n - circle - 1) {
                if (i == m - circle - 1) {
                    j--;
                    continue;
                }
                i++;
                continue;
            }
            if (i == m - circle - 1) {
                if (j == circle) {
                    i--;
                    continue;
                }
                j--;
                continue;
            }
            if (j == circle) {
                if (i == j + 1) {
                    j++;
                    circle++;
                    continue;
                }
                i--;
                continue;
            }
        }
        // 不加这行怎么也能过！！！
        return result;
    }
};