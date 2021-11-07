class Solution {
    int result = 0;
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        unordered_map<int, unordered_map<int, int>> m;
        for (auto &edge : edges) {
            m[edge[0]][edge[1]] = edge[2];
            m[edge[1]][edge[0]] = edge[2];
        }
        vector<int> visited(values.size(), 0);
        visited[0] = 1;
        result = values[0];
        helper(0, values, m, maxTime, visited, values[0]);
        return result;
    }
    void helper(int index, vector<int> &values, unordered_map<int, unordered_map<int, int>> &m, int remainTime, vector<int> &visited, int quality) {
        for (auto &mm : m[index]) {
            if (mm.second <= remainTime) {
                int node = mm.first;
                if (visited[node] == 0) {
                    quality += values[node];
                }
                if (node == 0) {
                    result = max(result, quality);
                }
                visited[node]++;
                helper(node, values, m, remainTime - mm.second, visited, quality);
                
                if (visited[node] == 1) {
                    quality -= values[node];
                }
                visited[node]--;
            }
        }
    }
};