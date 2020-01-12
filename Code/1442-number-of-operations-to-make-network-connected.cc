class Solution {
    bool has[100001];
    unordered_map<int, unordered_set<int>> m;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) {
            return -1;
        }
        
        for (auto &connection : connections) {
            m[connection[0]].insert(connection[1]);
            m[connection[1]].insert(connection[0]);
        }
        
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (!has[i]) {
                groups += 1;
                helper(i);
            }
        }
        
        return max(0, groups - 1);
    }
    
    void helper(int i) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (has[node]) {
                continue;
            }
            has[node] = true;
            for (auto cnct : m[node]) {
                if (has[cnct]) {
                    continue;
                }
                q.push(cnct);
            }
        }
    }
};