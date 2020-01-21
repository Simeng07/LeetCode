class Solution {
    vector<unordered_set<int>> edge;
        
    int currentIndex = 0;
    int index[100001] = {0};    // travel index
    int low[100001];            // the minimun index i can reach not via its parent
    
    vector<vector<int>> result;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        edge = vector(n, unordered_set<int>());
        for (auto connection : connections) {
            edge[connection[0]].insert(connection[1]);
            edge[connection[1]].insert(connection[0]);
        }

        for (int i = 0; i < n; i++) {
            index[i] = -1;
        }
        
        dfs(connections, 0, 0);
        
        return result;
    }
    
    void dfs(vector<vector<int>>& connections, int i, int parent) {
        index[i] = currentIndex;
        low[i] = currentIndex; // one can only reach onself not via its parent, for now
        currentIndex++;
        
        for (auto child : edge[i]) {
            if (child == parent) {
                continue;
            }
            if (index[child] < 0) {
                dfs(connections, child, i);
            }
            if (low[child] > index[i]) {
                // this child can't travel to a node before its parent
                result.push_back({i, child});
            }
            low[i] = min(low[i], low[child]);
        }
    }
};