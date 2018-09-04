class Solution {
public:
    int countPrimes(int n) {
        int a[n + 1] = {0};
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] == 0) {
                result++;
                for (int j = 2; j <= n / i; j++) {
                    a[i * j] = 1;
                }
            }
        }
        return result;
    }
};