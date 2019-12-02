class Solution {
public:
    bool isPowerOfThree(int n) {
        // if (n < 1) {
        //     return false;
        // }
        // double log3n = log10(n) / log10(3);
        // return ceil(log3n) == floor(log3n);
        // 为什么log(n) / log(3);不行？
        // 因为：
//         log(243) = 5.493061443340548    log(3) = 1.0986122886681098
//            ==> log(243)/log(3) = 4.999999999999999

//         log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
//            ==> log10(243)/log10(3) = 5.0
        // 巧合，不必多虑
        
        // return ((n > 0) && (1162261467 % n == 0)); // 3^19
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};