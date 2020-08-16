class Solution {
    unordered_map<int, int> m;
public:
    int minDays(int n) {
        if (m.find(n) != m.end()) {
            return m[n];
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2 || n == 3) {
            return 2;
        }
        int result = n;
        if (n % 2 == 0) {
            result = min(result, 1 + minDays(n / 2));
        }
        if (n % 2 == 1) {
            result = min(result, 2 + minDays(n / 2));
        }
        if (n % 3 == 0) {
            result = min(result, 1 + minDays(n / 3));
        }
        if (n % 3 == 1) {
            result = min(result, 2 + minDays(n / 3));
        }
        if (n % 3 == 2) {
            result = min(result, 3 + minDays(n / 3));
        }
        m[n] = result;
        return result;
    }
};