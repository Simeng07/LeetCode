class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
        // if (n < 1) {
        //     return false;
        // }
        // int count = 0;
        // while (n > 0) {
        //     if (n & 1 == 1) {
        //         count++;
        //         if (count > 1) {
        //             return false;
        //         }
        //     }
        //     n >>= 1;
        // }
        // return true;
    }
};