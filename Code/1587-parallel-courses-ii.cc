class Solution {
    int dependency[16] = {0};
    int dp[65536];
    int complete;
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        memset(dp, -1, sizeof(dp));
        complete = (1 << (n + 1)) - 2;
        for (int i = 0; i < dependencies.size(); i++) {
            dependency[dependencies[i][1]] |= (1 << dependencies[i][0]);
        }
        return helper(n, k, 0);
    }
    
    int helper(int n, int k, int current) {
        if (current == complete) {
            return 0;
        }
        if (dp[current] != -1) {
            return dp[current];
        }
        int todo = 0;
        for (int i = 1; i <= n; i++) {
            if (((1 << i) & current) == 0 && (dependency[i] & current) == dependency[i]) {
                todo |= (1 << i);
            }
        }
        int count = __builtin_popcount(todo);
        if (count <= k) {
            dp[current] = 1 + helper(n, k, current | todo);
            return dp[current];
        }
        dp[current] = INT_MAX;
        for (int i = todo; i > 0; i = ((i - 1) & todo)) {
            count = __builtin_popcount(i);
            if (count == k) {
                dp[current] = min(dp[current], 1 + helper(n, k, current | i));
            }
        }
        return dp[current];
    }
};