class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 || n==1) return 1;
        vector<int> v(m, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++)  {
                v[j] += v[j - 1];
            }
        }
        return v[m - 1];
    }
};