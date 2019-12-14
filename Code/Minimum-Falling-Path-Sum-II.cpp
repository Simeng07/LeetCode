class Solution {
    int size = 0;
    int dp[201][201] = {0};
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        size = arr.size();
        if (size == 1) {
            return arr[0][0];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < size; i++) {
            dp[0][i] = helper(arr, 0, i);
            result = min(result, dp[0][i]);
        }
        return result;
    }
    int helper(vector<vector<int>>& arr, int row, int column) {
        if (dp[row][column] != INT_MAX) {
            return dp[row][column];
        }
        if (row == size - 1) {
            dp[row][column] = arr[row][column];
            return dp[row][column];
        }
        for (int i = 0; i < size; i++) {
            if (i != column) {
                dp[row][column] = min(dp[row][column], arr[row][column] + helper(arr, row + 1, i));
            }
        }
        return dp[row][column];
    }
};