class Solution {
    int distance[100][100] = {0};
    int dp[100][100] = {0};
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        if (k == n) {
            return 0;
        }
        sort(houses.begin(), houses.end());
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int total = 0;
                for (int k = i; k <= j; k++) {
                    total += abs(houses[(i + j) / 2] - houses[k]);
                }
                distance[i][j] = total;
            }
        }
        return helper(houses, 0, k);
    }
    
    int helper(vector<int>& houses, int i, int k) {
        if (k == 1) {
            return distance[i][houses.size() - 1];
        }
        if (dp[i][k] != 0) {
            return dp[i][k];
        }
        int result = INT_MAX;
        for (int j = i; j <= houses.size() - k; j++) {
            result = min(result, distance[i][j] + helper(houses, j + 1, k - 1));
        }
        dp[i][k] = result;
        return result;
    }
};