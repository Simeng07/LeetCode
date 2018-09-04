class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t maskOrigin = 1;
        uint32_t maskResult = pow(2,31);
        for (int i = 0; i < 32; i++) {
            if ((n & maskOrigin) != 0) {
                result = result | maskResult;
            }
            maskOrigin <<= 1;
            maskResult >>= 1;
        }
        return result;
    }
};