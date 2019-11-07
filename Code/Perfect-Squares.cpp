class Solution {
public:
    int numSquares(int n) {
        int result[n + 1];
        if (n == 1) return 1;
        int maxSq = sqrt(n);
        result[0] = 0;
        result[1] = 1;
        for (int i = 2; i <= n; i++) {
            int maxSqTmp = sqrt(i);
            result[i] = INT_MAX;
            for (int j = 1; j <= maxSqTmp; j++) {
                result[i] = min(result[i], 1 + result[i - j * j]);
            }
        }
        return result[n];
    }
};