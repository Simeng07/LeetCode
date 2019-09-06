class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }
        
        unordered_map<int, unordered_set<int>> m;
        for (auto stone : stones) {
            m[stone] = unordered_set<int>{};
        }
        m[1].insert(1);
        
        for (int i = 1; i < stones.size(); i++) {
            unordered_set<int> currentUnits = m[stones[i]];
            if (i == stones.size() - 1 && currentUnits.empty()) {
                return false;
            }
            for (auto currentUnit : currentUnits) {
                for (int diff = -1; diff <= 1; diff++) {
                    int toPosition = stones[i] + currentUnit + diff;
                    if (m.find(toPosition) != m.end()) {
                        m[toPosition].insert(currentUnit + diff);
                    }
                }
            }
        }
        
        return true;
    }
};