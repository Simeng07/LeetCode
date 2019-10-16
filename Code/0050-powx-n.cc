class Solution {
public:
    double myPow(double x, int n) {
        long b = n;
        bool flag = b < 0;
        if (flag) b *= -1;
        double a = x;
        double result = 1;
        while (b > 0) {
            if (b & 1) {
                result *= a;
            }
            a *= a;
            b >>= 1;
        }
        return flag ? 1/result : result;
    }
};