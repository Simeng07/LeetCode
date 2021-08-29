class Solution {
    int dp[32768][14][16];
    int sTime;
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp, -1, sizeof(dp));
        int taskMask = (1 << tasks.size()) - 1;
        sTime = sessionTime;
        return helper(tasks, taskMask, 0, sessionTime);
    }
    int helper(vector<int>& tasks, int mask, int done, int current) {
        if (mask == 0) {
            if (current != sTime) {
                done++;
            }
            return done;
        }
        if (dp[mask][done][current] != -1) {
            return dp[mask][done][current];
        }
        int n = tasks.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int indexMask = (1 << i);
            if ((indexMask & mask) && tasks[i] <= current) {
                int tmpMask = (mask ^ indexMask);
                int tmpCurrent = current - tasks[i];
                int tmpDone = done;
                if (tmpCurrent == 0) {
                    tmpDone++;
                    tmpCurrent = sTime;
                }
                result = min(result, helper(tasks, tmpMask, tmpDone, tmpCurrent));
            }
        }
        if (current != 0 && current != sTime) {
            result = min(result, helper(tasks, mask, done + 1, sTime));
        }
        dp[mask][done][current] = result;
        return result;
    }
};