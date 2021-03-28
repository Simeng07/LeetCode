class Solution {
    int MOD = 1000000007;
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) {
            return 1;
        }
        long long power, mul;
        if (primeFactors % 3 == 0) {
            power = primeFactors / 3;
            mul = 1;
        } else if (primeFactors % 3 == 1) {
            power = (primeFactors - 4) / 3;
            mul = 4;
        } else {
            power = (primeFactors - 2) / 3;
            mul = 2;
        }
        long long result = myPow(power) * mul % MOD;
        return result;
    }
    
    int myPow(int p) {
        if (p == 1) {
            return 3;
        }
        long long tmp = 3;
        long long result = 1;
        for (; p > 0; p >>= 1) {
            if ((p & 1) != 0) {
                result *= tmp;
            }
            result %= MOD;
            tmp = (tmp * tmp) % MOD;
        }
        return (int)result;
    }
};