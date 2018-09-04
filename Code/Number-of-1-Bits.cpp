class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            // 要有括号
            if ((n & 1) > 0) {
                result++;
            }
            n >>= 1;
        }
        return result;
    }
};