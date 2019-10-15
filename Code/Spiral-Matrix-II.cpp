class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // #54 Spiral Matrix
        vector<vector<int>> b(n, vector<int>(n, 0));
        if (n == 0) return b;
    
        int cnt = 1;
        int i = 0;
        int j = 0;
        int circle = 0;
        while (cnt <= n * n) {
    
            b[i][j] = cnt;
            cnt++;
            if (i == circle) {
                if (j == n - circle - 1) {
                    i++;
                    continue;
                }
                j++;
                continue;
            }
            if (j == n - circle - 1) {
                if (i == n - circle - 1) {
                    j--;
                    continue;
                }
                i++;
                continue;
            }
            if (i == n - circle - 1) {
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
        return b;
    }
};