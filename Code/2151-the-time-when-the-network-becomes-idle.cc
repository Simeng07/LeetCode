class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int distance[500001] = {0};
        bool has[500001] = {0};
        unordered_map<int, unordered_set<int>> adj;
        for (auto &edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        unordered_set<int> current;
        current.insert(0);
        int dis = 1;
        while (!current.empty()) {
            unordered_set<int> tmp;
            for (auto it = current.begin(); it != current.end(); ++it) {
                // cout << "a " << *it << endl;
                for (auto it2 = adj[*it].begin(); it2 != adj[*it].end(); ++it2) {
                    // cout << "b " << *it2 << endl;
                    if (!has[*it2]) {
                        // cout << "c " << dis << endl;
                        has[*it2] = true;
                        distance[*it2] = dis;
                        tmp.insert(*it2);
                    }
                }
            }
            dis++;
            current = tmp;
        }
        
        int result = 0;
        for (int i = 1; i < patience.size(); i++) {
            result = max(result, ((2 * distance[i] - 1) / patience[i]) * patience[i] + 2 * distance[i] + 1);
        }
        
        return result;
    }
};