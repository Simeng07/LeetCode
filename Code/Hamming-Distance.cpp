class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x != 0 || y != 0) {
            if ((x & 1) ^ (y & 1)) {
                result++;
            }
            x >>= 1;
            y >>= 1;
        }
        return result;
        
        // 对的
        // int result = 0;
        // int z = x ^ y;
        // while (z != 0) {
        //     if (z & 1) result++;
        //     z >>= 1;
        // }
        // return result;
    }
};