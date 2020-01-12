class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if (n <= 10 || n == 10000) {
            return {1, n - 1};
        }
        
        int base = 1;
        int n1 = 0, n2 = 0;
        
        while (true) {
            int d1 = n % (10 * base) / base;
            int n1p = 0, n2p = 0;
            if (d1 == 1) {
                if (n == d1 * base) {
                    n1p = base;
                    n2p = 0;
                } else {
                    n1p = 2 * base;
                    n2p = 9 * base;
                }
            } else if (d1 == 0) {
                n1p = base;
                n2p = 9 * base;
            } else {
                n1p = base;
                n2p = d1 * base - base;
            }
            n1 += n1p;
            n2 += n2p;
            n = n - n1p - n2p;
            if (n <= 0) {
                return {n1, n2};
            }
            base *= 10;
        }
        
        return {n1, n2};
    }
};