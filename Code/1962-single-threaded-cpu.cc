class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        
        long long endTime = INT_MAX;
        map<int, set<pair<int, int>>> all; // beginTime, length, index
        for (int i = 0; i < tasks.size(); i++) {
            all[tasks[i][0]].insert({tasks[i][1], i});
            endTime = min(endTime, (long long)tasks[i][0]);
        }
        
        set<pair<int, int>> pool;
        auto mapIt = all.begin();
        
        while (true) {
            while (mapIt != all.end() && mapIt->first <= endTime) {
                pool.insert((mapIt->second).begin(), (mapIt->second).end());
                ++mapIt;
            }
            if (pool.empty() && mapIt == all.end()) {
                return result;
            }
            if (pool.empty()) {
                endTime = mapIt->first;
                while (mapIt != all.end() && mapIt->first <= endTime) {
                    pool.insert((mapIt->second).begin(), (mapIt->second).end());
                    ++mapIt;
                }
            }
            auto &currentTask = *(pool.begin());
            result.push_back(currentTask.second);
            endTime += currentTask.first;
            pool.erase(currentTask);
        }
        
        return result;
    }
};