class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result;
        
        vector<unordered_set<int> > edge(n, unordered_set<int>());
        for (auto connection : connections) {
            edge[connection[0]].insert(connection[1]);
            edge[connection[1]].insert(connection[0]);
        }
        
        vector<unordered_set<int> > count(n, unordered_set<int>());
        for (int i = 0; i < n; i++) {
            count[edge[i].size()].insert(i);
        }
        
        while (!count[1].empty()) {
            int server = *count[1].begin();
            int connectServer = *edge[server].begin();
            
            edge[server].erase(connectServer);
            edge[connectServer].erase(server);
            
            count[edge[connectServer].size()].insert(connectServer);
            count[edge[connectServer].size() + 1].erase(connectServer);
            count[1].erase(server);
            
            result.push_back({server, connectServer});
        }
        
        return result;
    }
};