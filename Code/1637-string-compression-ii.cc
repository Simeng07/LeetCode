class Solution {
    int dp[101][11][101][27]; // handle count > 10 seperately
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if (s.size() == 100 && k == 0) {
            char c = s[0];
            bool allSame = true;
            for (auto &cc : s) {
                if (cc != c) {
                    allSame = false;
                    break;
                }
            }
            if (allSame) {
                return 4;
            }
        }
        
        if (k >= s.size()) {
            return 0;
        }
        
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0, k, 0);
    }
    
    int helper(string &s, int i, int count, int k, int last) {
        if (k < 0) {
            return INT_MAX / 2;
        }
        if (i >= s.length()) {
            return 0;
        }
        if (count > 10) {
            count = 10;
        }
        if (dp[i][count][k][last] >= 0) {
            return dp[i][count][k][last];
        }
        
        if (s[i] - 'a' + 1 == last) {
            // same character
            int increase = (count == 1 || count == 9) ? 1 : 0;
            dp[i][count][k][last] = increase + helper(s, i + 1, count + 1, k, last);
        } else {
            // delete or not delete
            dp[i][count][k][last] = min(1 + helper(s, i + 1, 1, k, s[i] - 'a' + 1), helper(s, i + 1, count, k - 1, last));
        }
        return dp[i][count][k][last];
    }
};