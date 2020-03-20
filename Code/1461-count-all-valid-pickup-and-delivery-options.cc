class Solution {
public:
    int countOrders(int n) {
        long long result = 1;
        for (int i = 0; i < n; i++) {
            result *= (n - i) * (2 * n - 2 * i - 1); // (2 * n - 2 * i) * (2 * n - 2 * i - 1) / 2;
            result %= 1000000007;
        }
        return result;
    }
};