class Solution {
    int dp[1024][6][6][7][7];
    int M, N;
    int mask;
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        memset(dp, -1, sizeof(dp));
        M = m;
        N = n;
        mask = ((1 << (2 * n)) - 1);
        return helper(0, 0, 0, introvertsCount, extrovertsCount);
    }
    int helper(int last, int i, int j, int introvertsCount, int extrovertsCount) {
        if (i == M || introvertsCount < 0 || extrovertsCount < 0 || (introvertsCount == 0 && extrovertsCount == 0)) {
            return 0;
        }
        if (dp[last][i][j][introvertsCount][extrovertsCount] >= 0) {
            return dp[last][i][j][introvertsCount][extrovertsCount];
        }
        
        int up = (last >> (2 * (N - 1)));
        int left = (j == 0 ? 0 : (last & 3));
        
        int nextI = (j + 1 == N ? i + 1 : i);
        int nextJ = (j + 1 == N ? 0 : j + 1);
        
        // nobody
        int maxHappiness = helper((last << 2) & mask, nextI, nextJ, introvertsCount, extrovertsCount);
        
        // introvert
        int happiness;
        if (introvertsCount > 0) {
            happiness = 120;
            if (up == 1) happiness -= 60;
            if (up == 2) happiness -= 10;
            if (left == 1) happiness -= 60;
            if (left == 2) happiness -= 10;
            maxHappiness = max(maxHappiness, happiness + helper(((last << 2) | 1) & mask, nextI, nextJ, introvertsCount - 1, extrovertsCount));
        }
        
        // extroverts
        if (extrovertsCount > 0) {
            happiness = 40;
            if (up == 1) happiness -= 10;
            if (up == 2) happiness += 40;
            if (left == 1) happiness -= 10;
            if (left == 2) happiness += 40;
            maxHappiness = max(maxHappiness, happiness + helper(((last << 2) | 2) & mask, nextI, nextJ, introvertsCount, extrovertsCount - 1));
        }
        
        dp[last][i][j][introvertsCount][extrovertsCount] = maxHappiness;
        // cout << last << " " << i << " " << j << " " << introvertsCount << " " << extrovertsCount << " " << maxHappiness << endl;
        return dp[last][i][j][introvertsCount][extrovertsCount];
    }
};