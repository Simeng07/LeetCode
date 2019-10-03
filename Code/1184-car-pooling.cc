class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int count[1001] = {0};
        for (auto &trip : trips) {
            count[trip[1]] += trip[0];
            count[trip[2]] -= trip[0];
        }
        int totalCount = 0;
        for (int i = 0; i < 1001; i++) {
            totalCount += count[i];
            if (totalCount > capacity) {
                return false;
            }
        }
        return true;
    }
};