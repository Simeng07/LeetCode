class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n, 0);
        sum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + stones[i];
        }
        int maxDiff = sum[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            maxDiff = max(maxDiff, sum[i] - maxDiff);
        }
        return maxDiff;
    }
};