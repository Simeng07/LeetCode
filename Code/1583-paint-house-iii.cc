class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int origin[100] = {0};
        int last = 0, count = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (houses[i] == 0 || houses[i] == last) {
                continue;
            }
            if (houses[i] != last) {
                count++;
                last = houses[i];
            }
        }
        if (count > target) {
            return -1;
        }
        int dp[100][101][20]; // index, colorCount, lastColor
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                if (houses[0] != 0) {
                    dp[0][1][houses[0] - 1] = 0;
                } else {
                    for (int j = 0; j < n; j++) {
                        dp[0][1][j] = cost[i][j];
                    }
                }
            } else {
                for (int j = 0; j <= target; j++) {
                    for (int k = 0; k < n; k++) {
                        if (dp[i - 1][j][k] != INT_MAX) {
                            if (houses[i] != 0) {
                                if (houses[i] - 1 == k) {
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                                } else {
                                    dp[i][j + 1][houses[i] - 1] = min(dp[i][j + 1][houses[i] - 1], dp[i - 1][j][k]);
                                }
                            } else {
                                for (int color = 0; color < n; color++) {
                                    if (color == k) {
                                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][color]);
                                    } else {
                                        dp[i][j + 1][color] = min(dp[i][j + 1][color], dp[i - 1][j][k] + cost[i][color]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            result = min(result, dp[m - 1][target][i]);
        }
        if (result == INT_MAX) {
            result = -1;
        }
        return result;
    }
};