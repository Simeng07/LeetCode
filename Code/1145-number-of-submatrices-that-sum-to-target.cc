class Solution {
    int dp[300][300] = {0};
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
                dp[i][j] = sum;
                if (dp[i][j] == target) {
                    result++;
                }
                for (int k = 0; k < j; k++) {
                    if (dp[i][j] - dp[i][k] == target) {
                        result++;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int ii = 0; ii < i; ii++) {
                    dp[ii][j] += dp[i][j];
                    if (dp[ii][j] == target) {
                        result++;
                    }
                    for (int k = 0; k < j; k++) {
                        if (dp[ii][j] - dp[ii][k] == target) {
                            result++;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};