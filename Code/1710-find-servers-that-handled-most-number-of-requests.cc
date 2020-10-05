class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> handleNumber(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> currentTasks; // {task end time, server}
        
        vector<int> freeServerTmp(k, 0);
        for (int i = 0; i < k; i++) {
            freeServerTmp[i] = i;
        }
        set<int> freeServers(freeServerTmp.begin(), freeServerTmp.end());
        
        int count = arrival.size();
        
        for (int i = 0; i < count; i++) {
            // refresh task status
            while (!currentTasks.empty()) {
                auto p = currentTasks.top();
                if (p.first <= arrival[i]) {
                    freeServers.insert(p.second);
                    currentTasks.pop();
                } else {
                    break;
                }
            }
            
            // find free server
            if (freeServers.empty()) {
                // drop
            } else {
                auto server = freeServers.lower_bound(i % k);
                if (server == freeServers.end()) {
                    server = freeServers.begin();
                }
                currentTasks.push(make_pair(arrival[i] + load[i], *server));
                handleNumber[*server]++;
                freeServers.erase(*server);
            }
        }
        
        int busiestNum = 0;
        for (int i = 0; i < k; i++) {
            if (handleNumber[i] > busiestNum) {
                busiestNum = handleNumber[i];
            }
        }
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (handleNumber[i] == busiestNum) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};