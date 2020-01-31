class Solution {
    int mod = 1000000007;
public:
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long tmpa, tmpe, tmpi, tmpo, tmpu;
        for (int count = 1; count < n; count++) {
            tmpa = e + i + u;
            tmpe = a + i;
            tmpi = e + o;
            tmpo = i;
            tmpu = i + o;
            a = tmpa % mod;
            e = tmpe % mod;
            i = tmpi % mod;
            o = tmpo % mod;
            u = tmpu % mod;
        }
        return (a + e + i + o + u) % mod;
    }
};