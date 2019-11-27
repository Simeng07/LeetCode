class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) return 0;
        int result = 1;
        int base = a % 1337;
        for (int i = b.size() - 1; i >= 0; i--) {
            for (int j = 1; j <= b[i]; j++) {
                result = result * base % 1337;
            }
            int tmpBase = base;
            for (int j = 0; j < 9; j++) {
                base = base * tmpBase % 1337;
            }
        }
        return result;    
    }
    // 以下也对，不过感觉生生把medium题目做成了hard的= =
//     const int modNum = 1337;
//     const int patchScale = 1000000000;
//     const int patchSize = 9;
//     int result;
//     unordered_map<int, int> numToPow;
//     unordered_map<int, int> powToNum;
//     int wholeCircle;   // wholeCircle+1次方%1337就等于a了
//     int eachPatchMul;  // 每个patch需要额外乘的次数，例如应该是1000000000次方，但是实际上只要k次方就行了
// public:
//     int superPow(int a, vector<int>& b) {
//         a %= modNum;
//         if (a == 0) {
//             return 0;
//         }
        
//         result = 1;
        
//         numToPow[0] = 1;
//         int index = 1;
//         int current = 1;
//         wholeCircle = 1;
//         while (true) {
//             current *= a;
//             current %= modNum;
//             if (current == 0) {
//                 current = modNum;
//             }
//             // 在某次之后，一定能回到最初的a
//             if (current == a && index != 1) {
//                 wholeCircle = index - 1;
//                 eachPatchMul = patchScale % wholeCircle;
//                 break;
//             }
//             numToPow[index] = current;
//             powToNum[current] = index;
//             index++;
//         }
        
//         int endIndex = b.size() - 1;
//         while (endIndex >= 0) {
//             result *= helper(a, b, endIndex);
//             result %= modNum;
//             if (result == 0) {
//                 result = modNum;
//             }
//             endIndex -= patchSize;
//         }
        
//         return result;
//     }
    
//     int helper(int a, vector<int>& b, int endIndex) {
//         int count = 0;
//         int num = 0;
//         int mulFac = 1;
//         // 9位数字
//         while (count < patchSize && endIndex - count >= 0) {
//             num += b[endIndex - count] * mulFac;
//             mulFac *= 10;
//             count++;
//         }
//         num %= wholeCircle;
//         int mulTime = (b.size() - 1 - endIndex) / patchSize; // 还需要做多少1000000000次方
//         while (mulTime--) {
//             num *= eachPatchMul;
//             num %= wholeCircle;
//         }
//         return numToPow[num];
//     }
};