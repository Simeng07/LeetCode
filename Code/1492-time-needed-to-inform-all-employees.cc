class Solution {
    // from bottom to top should do better
    unordered_map<int, unordered_set<int>> subordinates;
    int result = 0;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < manager.size(); i++) {
            subordinates[manager[i]].insert(i);
        }
        helper(0, headID, informTime);
        return result;
    }
    void helper(int time, int manager, vector<int>& informTime) {
        if (subordinates.find(manager) == subordinates.end()) {
            result = max(result, time);
            return;
        }
        int t = time + informTime[manager];
        for (auto pp : subordinates[manager]) {
            helper(t, pp, informTime);
        }
    }
};