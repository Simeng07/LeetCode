class Solution {
public:
    int reverse(int x) {
        // INT_MIN, INT_MAX
        if (x == 0 || x == INT_MIN) {
            return 0;
        }
        int result = 0;
        bool pos = x > 0;
        if (!pos) {
            x = -x;
        }
        while (x > 0) {
            int remain = x % 10;
            if ((INT_MAX - remain) / 10 < result) {
                return 0;
            }
            result = result * 10 + remain;
            x /= 10;
        }
        if (!pos) {
            result = -result;
        }
        return result;
    }
};