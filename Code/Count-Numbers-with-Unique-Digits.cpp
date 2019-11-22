class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n > 10) n = 10;
        int result = 10;
        if (n == 1) return result;;
        int fac = 81;
        for (int i = 2; i <= n; i++) {
            result += fac;
            fac *= (10 - i);
        }
        return result;
        
        // switch(n) {
        //     case 0: return 1;
        //     case 1: return 10;
        //     case 2: return 91;
        //     case 3: return 739;
        //     case 4: return 5275;
        //     case 5: return 32491;
        //     case 6: return 168571;
        //     case 7: return 712891;
        //     case 8: return 2345851;
        //     case 9: return 5611771;
        //     default: return 8877691;
        // }

        // int a[] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
        // if (n <= 10) return a[n];
        // return a[10];
    }
};