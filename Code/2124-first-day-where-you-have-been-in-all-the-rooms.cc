class Solution {
    // https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1445225/Python-short-dp-explained/1072788
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        long long MOD = 1e9 + 7;
        int n = nextVisit.size();
        int dp[100000] = {0};
        for (int i = 1; i < n; i++) {
            dp[i] = (MOD + dp[i - 1] + 1 + (dp[i - 1] - dp[nextVisit[i - 1]] + 1)) % MOD;
        }
        return dp[n - 1];
    }
};