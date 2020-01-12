class Solution {
public:
    int minFlips(int a, int b, int c) {
        int base = 1;
        int result = 0;
        while (true) {
            if ((base > a && base > b && base > c ) || base < 0) {
                break;
            }
            int digit1 = a & base;
            int digit2 = b & base;
            int digit3 = c & base;
            if (digit3 > 0) {
                if (digit1 == 0 && digit2 == 0) {
                    result += 1;
                }
            } else {
                if (digit1 > 0) {
                    result += 1;
                }
                if (digit2 > 0) {
                    result += 1;
                }
            }
            base <<= 1;
        }
        return result;
    }
};