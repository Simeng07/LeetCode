class Solution {
    int dp[51][101][51];
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, n, m, k);
    }
    
    int helper(int index, int biggest, int cost, int n, int m, int k) {
        if (index == n) {
            if (cost == k) {
                return 1;
            } else {
                return 0;
            }
        }
        if (cost > k) {
            return 0;
        }
        if (dp[index][biggest][cost] > -1) {
            return dp[index][biggest][cost];
        }
        int result = 0;
        for (int i = 1; i <= m; i++) {
            result += helper(index + 1, max(biggest, i), cost + (i > biggest), n, m, k);
            result %= 1000000007;
        }
        dp[index][biggest][cost] = result;
        return result;
    }
};