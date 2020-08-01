class Solution {
    int dp[27][5001]; // 27 = 3 * 3 * 3
public:
    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, n, -1);
    }
    int helper(int index, int n, int last) {
        if (index == n) {
            return 1;
        }
        if (last != -1 && dp[last][index] >= 0) {
            return dp[last][index];
        }
        long result = 0;
        for (int i = 0; i < 3; i++) {
            if (last != -1 && (last / 9) % 3 == i) {
                continue;
            }
            for (int j = 0; j < 3; j++) {
                if ((last != -1 && (last / 3) % 3 == j) || i == j) {
                    continue;
                }
                for (int k = 0; k < 3; k++) {
                    if ((last != -1 && last % 3 == k) || j == k) {
                        continue;
                    }
                    int current = k + j * 3 + i * 9;
                    result += helper(index + 1, n, current);
                    result %= 1000000007;
                }
            }
        }
        if (last != -1) {
            dp[last][index] = result;
        }
        return result;
    }
};