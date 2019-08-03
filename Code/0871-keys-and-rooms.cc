class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> result(n, false);
        set<int> set;
        
        set.insert(0);
        
        while (!set.empty()) {
            int current = *set.begin();
            if (current >= n) {
                continue;
            }
            result[current] = true;
            set.erase(current);
            
            for (auto key : rooms[current]) {
                if (key >= n) {
                    continue;
                }
                if (result[key]) {
                    continue;
                }
                set.insert(key);
            }
        }
        
        for (auto r : result) {
            if (!r) {
                return false;
            }
        }
        
        return true;
    }
};