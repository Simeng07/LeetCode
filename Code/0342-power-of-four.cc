class Solution {
public:
    bool isPowerOfFour(int num) {
        bool flag = true;
        while (num > 0) {
            if (num & 1) {
                if (num != 1) return false;
                if (flag) return true;
                return false;
            }
            num >>= 1;
            flag = !flag;
        }
        return false;
    }
};