class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int cities[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cities[i][j] = (i == j ? 0 : 10001); // threshold + 1
            }
        }
        
        for (auto &edge : edges) {
            cities[edge[0]][edge[1]] = edge[2];
            cities[edge[1]][edge[0]] = edge[2];
        }
        
        // Floyd Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cities[i][j] = min(cities[i][j], cities[i][k] + cities[k][j]);
                    cities[j][i] = cities[i][j];
                }
            }
        }
        
        int resultNode = 0;
        int resultCount = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int tmpCount = 0;
            for (int j = 0; j < n; j++) {
                if (cities[i][j] <= distanceThreshold) {
                    tmpCount++;
                }
            }
            if (tmpCount <= resultCount) {
                resultNode = i;
                resultCount = tmpCount;
            }
        }
        
        return resultNode;
    }
};