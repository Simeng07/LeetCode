class Solution {
    // (a * b) % p = (a % p * b % p) % p 
    // a ^ b % p = ((a % p)^b) % p 
    
    // (2^p-2)^(2^(p-1)-1)*(2^p-1)%MOD
    long long MOD = 1e9 + 7;
public:
    int minNonZeroProduct(int p) {
        long long a = ((long long)pow(2, p) - 2) % MOD;
        long long b = (long long)pow(2, p - 1) - 1; // must convert to long long
        long long c = bn(a, b) % MOD;
        long long d = ((long long)pow(2, p) - 1) % MOD;
        long long result = c * d % MOD;
        return (int)result;
    }
    
    long long bn(long long b, long long n) {
        long long result = 1;
        while(n) {
            if(n & 1){
                result = (result * b) % MOD;
            }
            b = (b * b) % MOD;
            n >>= 1;
        }
        return result;
    }
};