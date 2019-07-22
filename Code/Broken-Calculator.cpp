class Solution {
    // int result;
public:
    int brokenCalc(int X, int Y) {
        // 这个是别人的方法，注释掉的是我的，原理一样，能过，超过65.4%，也还好^_^
        int result = 0;
        while (Y > X) {
            Y = Y % 2 > 0 ? Y + 1 : Y / 2;
            result++;
        }
        return result + X - Y;
        
//         result = 0;
//         helper(X, Y);
//         return result;
    }
    
//     void helper(int X, int Y) {
//         if (X >= Y) {
//             result += (X - Y);
//             return;
//         }
        
//         if (Y % 2 != 0) {
//             result += 1;
//             Y += 1;
//         }
        
//         Y /= 2;
//         result += 1;
        
//         helper(X, Y);
//     }
};