class Solution {
public:
    int getSum(int a, int b) {
        // int result = a;
        // while (b != 0) {
        //     result = a ^ b;
        // Line 7: Char 25: runtime error: left shift of negative value -2147483648 (solution.cpp) [case : -1 1]
        //     b = (a & b) << 1;
        //     a = result;
        // }
        // return result;
        
        // 以下也对 -> 也有问题了
        // 负数直接加就行了...补码表示，原来数字取反加1
        // int result = 0;
        // int dig = 0;
        // int carry = 0;
        // long mask = 1;
        // while (mask < pow(2, 32)) {
        //     dig = (a ^ b ^ carry) & mask;
        //     result |= dig;
        // Line 23: Char 19: runtime error: left shift of negative value -2147483648 (solution.cpp) [case : -1 1]
        //     carry = ((a & b) | (b & carry) | (a & carry)) & mask;
        //     carry <<= 1;
        //     mask <<= 1;
        // }
        // result |= carry;
        // return result;
        
        int result = 0;
        int dig = 0;
        int carry = 0;
        int mask = 1;
        while (true) {
            dig = (a ^ b ^ carry) & mask;
            result |= dig;
            carry = ((a & b) | (b & carry) | (a & carry)) & mask;
            if (mask < 0) { // 最左一位了
                dig = (a ^ b ^ carry) & mask;
                result |= dig;
                break;
            }
            mask <<= 1;
            carry <<= 1;
        }
        return result;
    }
};