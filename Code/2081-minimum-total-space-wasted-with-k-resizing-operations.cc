class Solution {
    int INF = 200 * 1e6;
    int dp[200][200];
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, k);
    }
    int helper(vector<int>& nums, int start, int k) {
        if (start == nums.size()) {
            return 0;
        }
        if (k == -1) {
            return INF;
        }
        if (dp[start][k] != -1) {
            return dp[start][k];
        }
        int result = INF;
        int maxNum = nums[start];
        int sum = 0;
        for (int i = start; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
            result = min(result, maxNum * (i - start + 1) - sum + helper(nums, i + 1, k - 1));
        }
        dp[start][k] = result;
        return result;
    }
};