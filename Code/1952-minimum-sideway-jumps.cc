class Solution {
    int dp[500002][3];
public:
    int minSideJumps(vector<int>& obstacles) {
        memset(dp, -1, sizeof(dp));
        return helper(obstacles, 0, 1);
    }
    int helper(vector<int>& obstacles, int point, int lane) {
        if (obstacles[point] == lane + 1) {
            return INT_MAX / 2;
        }
        if (point == obstacles.size() - 2) {
            return 0;
        }
        if (dp[point][lane] != -1) {
            return dp[point][lane];
        }
        int result = INT_MAX;
        if (obstacles[point + 1] != lane + 1) {
            result = helper(obstacles, point + 1, lane);
            dp[point][lane] = result;
            return result;
        }
        result = 1 + min(helper(obstacles, point, (lane + 1) % 3), helper(obstacles, point, (lane + 2) % 3));
        dp[point][lane] = result;
        return result;
    }
};