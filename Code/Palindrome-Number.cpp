class Solution {
public:
    bool isPalindrome(int x) {
        // 0-9可以
        // 负数或者以0结尾的数都不可以
        // 12345: 5-123; 54-12; 543-1; 543-12
        // 12321: 1-123; 12-12
        // 1221:  1-12; 12-1; 12=12
        
        if (x >= 0 && x <= 9) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int y = 0;
        while (y < x) {
            y = y * 10 + x % 10;
            x /= 10;
            if (x / 10 == y) {
                return true;
            }
        }
        return x == y;
    }
};