class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int a = 1;
        int b = 1;
        int result;
        for (int i = 2; i <= n; i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};