class Solution {
    int dp[500][500];
    string s;
public:
    int minInsertions(string originS) {
        s = originS;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                dp[i][j] = -1;
            }
        }
        return helper(0, s.size() - 1);
    }
    
    int helper(int i, int j) {
        if (i == j) {
            return 0;
        }
        
        if (dp[i][j] >= 0) {
            return dp[i][j];
        }
        
        int result;
        if (s[i] == s[j]) {
            result = helper(i + 1, j - 1);
        } else {
            result = 1 + min(helper(i + 1, j), helper(i, j - 1));
        }
        dp[i][j] = result;
        
        return result;
    }
};