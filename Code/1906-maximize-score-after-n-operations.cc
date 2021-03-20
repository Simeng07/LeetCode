class Solution {
    int gcd[14][14] = {0};
    int dp[8][1 << 14];
public:
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        int left = (1 << n) - 1;
        return helper(1, left, nums);
    }
    
    int helper(int times, int left, vector<int>& nums) {
        if (left == 0) {
            return 0;
        }
        if (dp[times][left] != -1) {
            return dp[times][left];
        }
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (left & (1 << i)) {
                for (int j = i + 1; j < n; j++) {
                    if (left & (1 << j)) {
                        result = max(result, gcd[i][j] * times + helper(times + 1, left - (1 << i) - (1 << j), nums));
                    }
                }
            }
        }
        dp[times][left] = result;
        return result;
    }
};