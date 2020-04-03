class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, unordered_set<int>> m;
        for (auto &edge : edges) {
            m[edge[1]].insert(edge[0]);
            m[edge[0]].insert(edge[1]);
        }
        queue<vector<double>> q;
        q.push({1, 1, 1}); // current index, posibility, last index
        double result = 0;
        for (int i = 0; i < t; i++) {
            int count = q.size();
            for (int j = 0; j < count; j++) {
                vector<double> &v = q.front();
                if (m[(int)v[0]].size() == 0 || (m[(int)v[0]].size() == 1 && (int)v[0] != (int)v[2])) {
                    // no more moves
                    if (v[0] == target) {
                        result += v[1];
                    }
                    q.pop();
                    continue;
                }
                for (auto vertex : m[(int)v[0]]) {
                    if ((int)v[2] != vertex) {
                        double posibility = v[1] / (m[(int)v[0]].size() - ((int)v[0] == (int)v[2] ? 0 : 1));
                        q.push({(double)vertex, posibility, v[0]});
                        if (i == t - 1 && vertex == target) {
                            result += posibility;
                        }
                    }
                }
                q.pop();
            }
        }
        return result;
    }
};