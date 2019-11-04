class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int result = 0;
        int fac = 1;
        while (fac <= n) {
            int current = n / fac % 10;
            int left = n / fac / 10;
            int right = n % fac;

            result += left * fac;
            if (current == 1) result += right + 1;
            if (current > 1) result += fac;
            if (fac <= INT_MAX / 10) {
                fac *= 10;
            } else {
                break;
            }
        }
        return result;
    }
};