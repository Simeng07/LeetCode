class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mod = 1e9 + 7;
        unordered_map<int, int> m;
        int ones = 0, result = 0;
        int dp[1 << 10] = {0};
        int tmp[1 << 10] = {0};
        dp[0] = 1;
        
        for (auto num : nums) {
            if (num % 4 == 0 || num % 9 == 0 || num % 25 == 0) {
                continue;
            }
            if (num == 1) {
                ones++;
            } else {
                m[num]++;
            }
        }
        
        for (auto mm : m) {
            int currentMask = 0;
            for (int i = 0; i < 10; i++) {
                if (mm.first % primes[i] == 0) {
                    currentMask += (1 << i);
                }
            }
            
            memset(tmp, 0, sizeof(tmp));
            for (int mask = 0; mask < (1 << 10); mask++) {
                if ((currentMask & mask) == 0) {
                    tmp[currentMask + mask] = ((long long)dp[mask] *(long long)mm.second) % mod;
                }
            }
            
            for (int i = 0; i < (1 << 10); i++) {
                dp[i] = (dp[i] + tmp[i]) % mod;
            }
        }
        
        for (int i = 1; i < (1 << 10); i++) {
            result = (result + dp[i]) % mod;
        }
        
        while (ones--) {
            result = ((long long)result * 2) % mod;
        }
        
        return result;
    }
};