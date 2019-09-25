class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        switch (n % 3) {
            case 1: {
                return 4 * pow(3, n / 3 - 1);
            }
            case 2: {
                return 2 * pow(3, n / 3);
            }
            default: {
                return pow(3, n / 3);
            }
        }
        return 0;
    }
};