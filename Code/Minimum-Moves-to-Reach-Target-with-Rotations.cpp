class Solution {
    int dp[100][100][2];
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int size = grid.size();
        if (grid[size - 1][size - 2] == 1 || grid[size - 1][size - 1] == 1) {
            return -1;
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                int tmpMin = INT_MAX;
                
                if (grid[i][j] == 0 && grid[i][j + 1] == 0) {
                    // horizontal
                    if (j - 1 >= 0 && dp[i][j - 1][0] != -1) {
                        // right
                        tmpMin = min(tmpMin, dp[i][j - 1][0] + 1);
                    }
                    if (i - 1 >= 0 && dp[i - 1][j][0] != -1) {
                        // down
                        tmpMin = min(tmpMin, dp[i - 1][j][0] + 1);
                    }
                    if (i + 1 < size && grid[i + 1][j + 1] == 0 && dp[i][j][1] != -1) {
                        // rotate
                        tmpMin = min(tmpMin, dp[i][j][1] + 1);
                    }
                    if (tmpMin != INT_MAX) {
                        dp[i][j][0] = tmpMin;
                    }
                }
                
                tmpMin = INT_MAX;
                
                if (i + 1 < size && grid[i][j] == 0 && grid[i + 1][j] == 0) {
                    // vertical
                    if (j - 1 >= 0 && dp[i][j - 1][1] != -1) {
                        // right
                        tmpMin = min(tmpMin, dp[i][j - 1][1] + 1);
                    }
                    if (i - 1 >= 0 && dp[i - 1][j][1] != -1) {
                        // down
                        tmpMin = min(tmpMin, dp[i - 1][j][1] + 1);
                    }
                    if (grid[i + 1][j + 1] == 0 && dp[i][j][0] != -1) {
                        // rotate
                        tmpMin = min(tmpMin, dp[i][j][0] + 1);
                    }
                    if (tmpMin != INT_MAX) {
                        dp[i][j][1] = tmpMin;
                    }
                }
                if (dp[i][j][1] != -1 && dp[i][j][0] == -1 && grid[i][j + 1] == 0 && grid[i + 1][j + 1] == 0) {
                    dp[i][j][0] = dp[i][j][1] + 1;
                }
            }
        }
        
        return dp[size - 1][size - 2][0];
    }
};