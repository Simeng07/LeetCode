// iteration is much faster. i = n - 1 ~ 0

class Solution {
    int dp[100001];
public:
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(s, k, 0);
    }
    
    int helper(string &s, int k, int index) {
        if (index == s.size()) {
            return 1;
        }
        if (index > s.size() || s[index] == '0') {
            return 0;
        }
        if (dp[index] >= 0) {
            return dp[index];
        }
        int count = 0;
        int length = 1;
        while (index + length <= s.size()) {
            string substr = s.substr(index, length);
            long substrNum = stol(substr);
            if (substrNum > k) {
                break;
            }
            count += helper(s, k, index + length);
            count %= 1000000007;
            length++;
        }
        dp[index] = count;
        return dp[index];
    }
};