class Solution {
    int dp[100][100];
    int lastSame[100];
public:
    int strangePrinter(string s) {
        int lastChar[26];
        fill(lastChar, lastChar + 26, -1);
        for (int i = 0; i < s.length(); i++) {
            lastSame[i] = lastChar[s[i] - 'a'];
            lastChar[s[i] - 'a'] = i;
        }
        return subStrangePrinter(s, 0, (int)s.length() - 1);
    }
    
    int subStrangePrinter(string &s, int begin, int end) {
        if (begin > end || begin < 0 || end < 0 || begin >= s.length() || end >= s.length()) {
            return 0;
        }
        if (begin == end) {
            return 1;
        }
        if (dp[begin][end] != 0) {
            return dp[begin][end];
        }
        
        dp[begin][begin] = 1;
        
        for (int i = begin + 1; i <= end; i++) {
            if (dp[begin][i] != 0) {
                continue;
            }
            if (i == begin) {
                dp[begin][i] = 1;
            } else {
                dp[begin][i] = dp[begin][i - 1] + 1;
                int lastIndex = lastSame[i];
                while (lastIndex >= begin) {
                    dp[begin][i] = min(dp[begin][i], dp[begin][lastIndex] + subStrangePrinter(s, lastIndex + 1, i - 1));
                    lastIndex = lastSame[lastIndex];
                }
            }
        }
        return dp[begin][end];
    }
};