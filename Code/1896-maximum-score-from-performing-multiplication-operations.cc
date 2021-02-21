class Solution {
    int dp[1000][1000];
    int n;
    int m;
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        int result = helper(nums, multipliers, 0, 0);
        return result;
    }
    
    int helper(vector<int>& nums, vector<int>& multipliers, int begin, int rBegin) {
        int index = begin + rBegin;
        if (index >= m) {
            return 0;
        }
        if (dp[begin][rBegin] != INT_MIN) {
            return dp[begin][rBegin];
        }
        
        int left = multipliers[index] * nums[begin] + helper(nums, multipliers, begin + 1, rBegin);
        int right = multipliers[index] * nums[n - 1 - rBegin] + helper(nums, multipliers, begin, rBegin + 1);
        
        dp[begin][rBegin] = max(left, right);
        return dp[begin][rBegin];
    }
};