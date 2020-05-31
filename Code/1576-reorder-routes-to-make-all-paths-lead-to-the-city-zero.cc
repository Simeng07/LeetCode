class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> directed;
        unordered_map<int, unordered_set<int>> undirected;
        for (auto &connection : connections) {
            directed[connection[0]].insert(connection[1]);
            undirected[connection[0]].insert(connection[1]);
            undirected[connection[1]].insert(connection[0]);
        }
        queue<int> q;
        q.push(0);
        vector<bool> has(n, false);
        has[0] = 1;
        int result = 0;
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            has[index] = true;
            for (auto next : undirected[index]) {
                if (!has[next]) {
                    if (directed[index].find(next) != directed[index].end()) {
                        result++;
                    }
                    q.push(next);
                }
            }
        }
        return result;
    }
};