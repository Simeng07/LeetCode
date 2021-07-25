class Solution {
    int dp[300];
    int scores[8][8];
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        // __builtin_popcount (4);
        memset(dp, -1, sizeof(dp));
        int n = students.size();
        vector<int> s(n);
        vector<int> m(n);
        for (int i = 0; i < n; i++) {
            int a = 0, b = 0;
            for (int j = 0; j < students[i].size(); j++) {
                if (students[i][j] == 1) {
                    a |= (1 << j);
                }
                if (mentors[i][j] == 1) {
                    b |= (1 << j);
                }
            }
            s[i] = a;
            m[i] = b;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scores[i][j] = students[i].size() - __builtin_popcount(s[i] ^ m[j]);
            }
        }
        int totalM = (1 << n) - 1;
        int result = helper(totalM, 0);
        return result;
    }
    
    int helper(int m, int index) {
        if (m == 0) {
            return 0;
        }
        if (dp[m] != -1) {
            return dp[m];
        }
        int result = 0;
        for (int i = 0; i < 8; i++) {
            int mask = (1 << i);
            if (m & mask) {
                m -= mask;
                result = max(result, scores[index][i] + helper(m, index + 1));
                m += mask;
            }
        }
        dp[m] = result;
        return result;
    }
};