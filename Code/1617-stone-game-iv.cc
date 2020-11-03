class Solution {
    int dp[100001];
public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
    
    bool helper(int n) {
        if (n == 0) {
            return false;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        bool result = true;
        for (int i = 1; i * i <= n; i++) {
            result = !helper(n - i * i);
            if (result) {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }
};