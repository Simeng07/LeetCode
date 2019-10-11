class Solution {
    int modNum = 1000000007;
public:
    int nthMagicalNumber(int N, int A, int B) {
        if (A > B) {
            return nthMagicalNumber(N, B, A);
        }
        long long result = 0;
        int gcd = findGcd(A, B);        // 最大公约数
        int lcm = A * B / gcd;          // 最小公倍数
        int n = A / gcd + B / gcd - 1;  // 到达最小公倍数时，一共走了几次
        if (n == N) {
            return lcm;
        }
        // 2. 算出用了N/n次后的最小公倍数的%
        int patchCount = N / n;
        if (patchCount >= 1) {
            result = (long long)patchCount * lcm % modNum;
        }
        int patchRemain = N % n;
        if (patchRemain == 0) {
            return (int)result;
        }
        // 3. 正常算剩余部分
        long long tmpa = result + A, tmpb = result + B;
        for (int i = 1; i < patchRemain; i++) {
            result = min(tmpa, tmpb);
            if (result == tmpa) {
                int counta = (int)(tmpb - tmpa) / A;
                if (counta > 1) {
                    if (counta < patchRemain - i) {
                        i += (counta - 1);
                        tmpa += A * counta;
                    } else {
                        return (int)((tmpa + A * (patchRemain - i)) % modNum);
                    }
                } else {
                    tmpa += A;
                }
            }
            if (result == tmpb) {
                tmpb += B;
            }
        }
        result = min(tmpa, tmpb) % modNum;
        return (int)result;
    }
    
    int findGcd(int a, int b) {
        int remain = b % a;
        if (remain == 0) {
            return a;
        } else {
            return findGcd(remain, a);
        }
    }
};