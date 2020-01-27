class Solution {
    int dp[300][300][11];
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size = jobDifficulty.size();
        if (size < d) {
            return -1;
        }
        for (int i = 0; i < size; i++) {
            dp[i][i][1] = jobDifficulty[i];
            for (int j = i + 1; j < size; j++) {
                dp[i][j][1] = max(dp[i][j - 1][1], jobDifficulty[j]);
                for (int k = 2; k <= d; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return subDiff(jobDifficulty, 0, size - 1, d);
    }
    
    int subDiff(vector<int>& jobDifficulty, int i, int j, int d) {
        if (dp[i][j][d] >= 0) {
            return dp[i][j][d];
        }
        int result = INT_MAX / 2;
        // keep the subDiff valid. the size of jobs >= days
        for (int k = 0; k <= min(j - i - 1, j - i + 1 - d); k++) {
            result = min(result, subDiff(jobDifficulty, i, i + k, 1) + subDiff(jobDifficulty, i + k + 1, j, d - 1));
        }
        dp[i][j][d] = result;
        return result;
    }
};