class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int a[m + 1][n + 1];
        memset(a, 0, sizeof(a));
        int size = strs.size();
        for (int i = 0; i < size; i++) {
            int c0 = 0, c1 = 0;
            for (auto c : strs[i]) {
                if (c == '1') {
                    c1++;
                } else {
                    c0++;
                }
            }
            // a[j][k] is refreshed after each patch
            for (int j = m; j >= c0; j--) {
                for (int k = n; k >= c1; k--) {
                    a[j][k] = max(a[j][k], a[j - c0][k - c1] + 1);
                }
            }
        }
        return a[m][n];
    }
};