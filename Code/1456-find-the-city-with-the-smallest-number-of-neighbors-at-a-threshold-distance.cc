class Solution {
    int result[100][100];
    int cities[100][100];
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = -1;
                cities[i][j] = -1;
            }
        }
        
        for (auto &edge : edges) {
            cities[edge[0]][edge[1]] = edge[2];
            cities[edge[1]][edge[0]] = edge[2];
        }
        
        for (int i = 0; i < n; i++) {
            helper(n, i, distanceThreshold);
        }
        
        int solutionNode = 0;
        int solutionCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (result[i][j] >= 0) {
                    tmp++;
                }
            }
            if (tmp < solutionCount) {
                solutionNode = i;
                solutionCount = tmp;
            }
            if (tmp == solutionCount) {
                solutionNode = max(solutionNode, i);
            }
        }
        
        return solutionNode;
    }
    
    void helper(int n,int current, int distanceThreshold) {
        for (int i = 0; i < n; i++) {
            if (i != current && cities[current][i] > 0 && distanceThreshold - cities[current][i] >= 0) {
                subHelper(n, i, distanceThreshold - cities[current][i], current, current);
            }
        }
    }
    
    void subHelper(int n, int current, int remain, int last, int origin) {
        result[origin][current] = remain;
        for (int i = 0; i < n; i++) {
            if (i != origin 
                && i != last 
                && i != current
                && cities[current][i] > 0
                && remain - cities[current][i] > result[origin][i]) {
                subHelper(n, i, remain - cities[current][i], i, origin);
            }
        }
    }
};