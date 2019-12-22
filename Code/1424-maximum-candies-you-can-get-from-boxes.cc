class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> gainedKeys;
        unordered_set<int> gainedBoxes;
        unordered_set<int> hasHandled;
        int result = 0;
        for (auto initialBox : initialBoxes) {
            gainedBoxes.insert(initialBox);
            if (status[initialBox] == 1) {
                gainedKeys.insert(initialBox);
            }
            for (auto key : keys[initialBox]) {
                gainedKeys.insert(key);
            }
            for (auto containedBox : containedBoxes[initialBox]) {
                gainedBoxes.insert(containedBox);
                if (status[containedBox] == 1) {
                    gainedKeys.insert(containedBox);
                }
            }
        }
        
        while (gainedKeys.size() > 0) {
            bool hasNew = false;
            unordered_set<int> newKeys;
            unordered_set<int> usedKeys;
            for (auto key : gainedKeys) {
                // cout << "handle: " << key << endl;
                if (gainedBoxes.find(key) != gainedBoxes.end()) {
                    // cout << "hasBox: " << key << endl;
                    hasHandled.insert(key);
                    usedKeys.insert(key);
                    // cout << key << " " << candies[key] << endl;
                    result += candies[key];
                    for (auto innerKey : keys[key]) {
                        if (hasHandled.find(innerKey) == hasHandled.end()) {
                            newKeys.insert(innerKey);
                            hasNew = true;
                        }
                    }
                    for (auto containedBox : containedBoxes[key]) {
                        if (hasHandled.find(containedBox) == hasHandled.end()) {
                            hasNew = true;
                            gainedBoxes.insert(containedBox);
                            if (status[containedBox] == 1) {
                                newKeys.insert(containedBox);
                            }
                        }
                    }
                    
                }
            }
            if (!hasNew) {
                return result;
            }
            gainedKeys.insert(newKeys.begin(), newKeys.end());
            for (auto usedKey : usedKeys) {
                gainedKeys.erase(usedKey);
            }
        }
        return result;
    }
};