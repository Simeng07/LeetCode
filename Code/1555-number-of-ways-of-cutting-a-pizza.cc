class Solution {
    int dp[50][50][11];
    int m, n;
public:
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        m = pizza.size();
        n = pizza[0].size();
        return helper(pizza, 0, 0, k - 1);
    }
    
    int helper(vector<string>& pizza, int i, int j, int k) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (k == 0) {
            return check(pizza, i, j, m - 1, n - 1);
        }
        if (dp[i][j][k] >= 0) {
            return dp[i][j][k];
        }
        long long result = 0;
        bool vertical = false, horizontal = false;
        for (int ii = i; ii < m; ii++) {
            if (horizontal || check(pizza, ii, j, ii, n - 1)) {
                horizontal = true;
                result += helper(pizza, ii + 1, j, k - 1);
            }
        }
        for (int jj = j; jj < n; jj++) {
            if (vertical || check(pizza, i, jj, m - 1, jj)) {
                vertical = true;
                result += helper(pizza, i, jj + 1, k - 1);
            }
        }
        result %= 1000000007;
        dp[i][j][k] = result;
        return result;
    }
    
    int check(vector<string>& pizza, int i, int j, int ei, int ej) {
        for (int ii = i; ii <= ei; ii++) {
            for (int jj = j; jj <= ej; jj++) {
                if (pizza[ii][jj] == 'A') {
                    return 1;
                }
            }
        }
        return 0;
    }
};