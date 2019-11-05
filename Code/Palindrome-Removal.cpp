class Solution {
    int dp[101][101] = {0};
public:
    int minimumMoves(vector<int>& arr) {
        int size = arr.size();
        if (size == 1) {
            return 1;
        }
        
        int dp[101][101] = {0};
        
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i; j < size; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if (i + 1 == j) {
                    dp[i][j] = (arr[i] == arr[j] ? 1 : 2);
                    continue;
                }
                dp[i][j] = dp[i + 1][j - 1] + (arr[i] == arr[j] ? 0 : 2);
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        
        return dp[0][size - 1];
    }
};