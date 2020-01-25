class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int dp[10001];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = n + 2;
        }
        for (int i = 0; i < n + 1; i++) {
            int startIndex = 0;
            int startCount = 0;
            if (i - ranges[i] > 0) {
                startIndex = i - ranges[i] + 1;
                startCount = dp[i - ranges[i]];
            }
            int endIndex = min(n, i + ranges[i]);
            for (int j = startIndex; j <= endIndex; j++) {
                dp[j] = min(dp[j], startCount + 1);
            }
        }
        return (dp[n] == n + 2 ? -1 : dp[n]);
    }
};