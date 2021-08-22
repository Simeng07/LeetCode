class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        unordered_set<int> s;
        for (int i = 0; i < mat.size(); i++) {
            auto &v = mat[i];
            unordered_set<int> ss;
            int currentMin = INT_MAX;
            int currentMinGreaterThanTarget = INT_MAX;
            for (auto n : v) {
                for (auto origin : s) {
                    int newValue = origin + n;
                    currentMin = min(currentMin, newValue);
                    if (newValue > target) {
                        currentMinGreaterThanTarget = min(currentMinGreaterThanTarget, newValue);
                    }
                    if (newValue <= target || i == mat.size() - 1) {
                        ss.insert(newValue);
                    }
                }
                if (i == 0) {
                    ss.insert(n);
                }
            }
            if (currentMin != INT_MAX) {
                ss.insert(currentMin);
            }
            if (currentMinGreaterThanTarget != INT_MAX) {
                ss.insert(currentMinGreaterThanTarget);
            }
            s = ss;
        }
        
        int result = INT_MAX;
        for (auto num : s) {
            result = min(result, abs(num - target));
            if (result == 0) {
                return result;
            }
        }
        return result;
    }
};