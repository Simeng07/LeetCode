class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9 + 7;
        int zero = 0, one = 0;
        for (auto c : binary) {
            if (c == '0') {
                zero = (zero + one) % mod;
            } else {
                one = (zero + one + 1) % mod;
            }
        }
        return (one + zero + (zero || binary[0] == '0')) % mod;
    }
};