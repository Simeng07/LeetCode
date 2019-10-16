class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<long long> v;
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (flag && obstacleGrid[0][i] == 1) {
                flag = false;
            }
            v.push_back(flag ? 1 : 0);
        }
        
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[i][0] == 0 && v[0] == 1) {
                v[0] = 1;
            } else {
                v[0] = 0;
            }
            for (int j = 1; j < m; j++)  {
                if (obstacleGrid[i][j] == 1) {
                    v[j] = 0;
                } else {
                    v[j] += v[j - 1];
                }
            }
        }
        return (int)v[m - 1];
    }
};