class Solution {
    int dp[102][102];
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        return helper(cuts, 0, cuts.size() - 1);
    }
    int helper(vector<int>& cuts, int begin, int end) {
        if (dp[begin][end] >= 0) {
            return dp[begin][end];
        }
        int minCuts = INT_MAX;
        for (int i = begin + 1; i < end; i++) {
            minCuts = min(minCuts, helper(cuts, begin, i) + helper(cuts, i, end));
        }
        if (minCuts == INT_MAX) {
            dp[begin][end] = 0;
            return 0;
        }
        dp[begin][end] = minCuts + cuts[end] - cuts[begin];
        return dp[begin][end];
    }
};