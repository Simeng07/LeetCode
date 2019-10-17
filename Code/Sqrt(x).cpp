class Solution {
public:
    int mySqrt(int x) {
        if (x < 4) {
            return x == 0 ? 0 : 1;
        }
        long long result = 2 * mySqrt(x / 4);
        if ((result + 1) * (result + 1) <= x && (result + 1) * (result + 1) >= 0) {
            result += 1;
        }
        return result;
    }
};