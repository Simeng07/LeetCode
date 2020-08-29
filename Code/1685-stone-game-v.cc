class Solution {
    int dp[500][500];
    int sum[500];
public:
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        sum[0] = stoneValue[0];
        for (int i = 1; i < stoneValue.size(); i++) {
            sum[i] = sum[i - 1] + stoneValue[i];
        }
        return helper(stoneValue, 0, stoneValue.size() - 1);
    }
    
    int helper(vector<int>& stoneValue, int start, int end) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int total = sum[end] - (start == 0 ? 0 : sum[start - 1]);
        int result = 0;
        for (int i = start; i < end; i++) {
            int tmpResult = 0;
            int right = sum[end] - sum[i];
            int left = total - right;
            if (left > right) {
                tmpResult += right;
                tmpResult += helper(stoneValue, i + 1, end);
            } else if (left < right) {
                tmpResult += left;
                tmpResult += helper(stoneValue, start, i);
            } else {
                tmpResult += left;
                tmpResult += max(helper(stoneValue, i + 1, end), helper(stoneValue, start, i));
            }
            result = max(result, tmpResult);
        }
        dp[start][end] = result;
        return result;
    }
};