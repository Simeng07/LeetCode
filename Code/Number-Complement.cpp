class Solution {
public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        long long mask = 1;
        mask <<= 31;
        int count = 0;
        while ((num & mask) == 0 && count < 32) {
            count++;
            mask >>= 1;
        }
        while (count < 32) {
            count++;
            num ^= mask;
            mask >>= 1;
        }
        return num;
        
        // 对的
        // int result = 0;
        // int pos = 0;
        // while (num != 0) {
        //     result |= (((num & 1) ^ 1) << pos);
        //     pos++;
        //     num >>= 1;
        // }
        // return result;
    }
};