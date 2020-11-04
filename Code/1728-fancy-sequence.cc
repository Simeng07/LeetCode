class Fancy {
    int MOD = 1000000007;
    vector<int> num;
    vector<long long> mul;
    vector<long long> sum;
public:
    Fancy() {
        mul.push_back(1);
        sum.push_back(0);
    }
    
    void append(int val) {
        num.push_back(val);
        mul.push_back(mul[mul.size() - 1]);
        sum.push_back(sum[sum.size() - 1]);
    }
    
    void addAll(int inc) {
        sum[sum.size() - 1] = (sum[sum.size() - 1] + inc) % MOD;
    }
    
    void multAll(int m) {
        mul[mul.size() - 1] = mul[mul.size() - 1] * m % MOD;
        sum[sum.size() - 1] = sum[sum.size() - 1] * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= num.size())
            return -1;
        //Given Fermat Little Theorem 
        //   1 ≡ a^(m-1) (mod m) 
        //=> a^-1 ≡ a^(m-2) (mod m)
        //Let a = mul[idx], m = MOD
        //So mul.last()/mul[idx] 
        //=> mul.last()*mul[idx]^-1 
        //=> mul.last()*mul[idx]^(mod-2) 
        //=> mul.last() * powMod(mul[idx], MOD - 2, MOD)
        long long m = mul[mul.size() - 1] * powMod(mul[idx], MOD - 2, MOD) % MOD;
        long long inc = sum[sum.size() - 1] + MOD - sum[idx] * m % MOD;
        return (int)((num[idx] * m + inc) % MOD);
    }
    
    int powMod(long long x, long long y, int mod) {
        long long result = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                result = result * x % mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return result;
    }
};

// https://leetcode.com/problems/fancy-sequence/discuss/898861/C%2B%2B-Math-Solution-O(1)-extra-space-and-O(1)-time-for-each
// https://leetcode.com/problems/fancy-sequence/discuss/900010/C-O(1)-Solution
// https://leetcode.com/problems/fancy-sequence/discuss/905064/C%2B%2BPython-O(1)

// Right, but TLE:
//
// class Fancy {
//     vector<int> sequence;
//     vector<pair<short, int>> instructions;
//     unordered_map<int, int> s2iIndex;
//     unordered_map<int, pair<int, int>> cache;
//     int MOD = 1000000007;
// public:
//     Fancy() {
        
//     }
    
//     void append(int val) {
//         s2iIndex[sequence.size()] = instructions.size();
//         sequence.push_back(val);
//         instructions.push_back({0, 0});
//     }
    
//     void addAll(int inc) {
//         instructions.push_back({1, inc});
//     }
    
//     void multAll(int m) {
//         instructions.push_back({2, m});
//     }
    
//     int getIndex(int idx) {
//         if (idx >= sequence.size()) {
//             return -1;
//         }
//         long long result;
//         int beginIndex;
//         if (cache.find(idx) != cache.end()) {
//             result = cache[idx].second;
//             beginIndex = cache[idx].first + 1;
//         } else {
//             result = sequence[idx];
//             beginIndex = s2iIndex[idx] + 1;
//         }
//         for (int i = beginIndex; i < instructions.size(); i++) {
//             auto &p = instructions[i];
//             if (p.first == 1) {
//                 result += p.second;
//                 result %= MOD;
//             } else if (p.first == 2) {
//                 result *= p.second;
//                 result %= MOD;
//             }
//         }
//         cache[idx] = {instructions.size() - 1, (int)result};
//         return (int)result;
//     }
// };

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */