class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> s;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int minNum = matrix[i][0];
            for (int j = 1; j < n; j++) {
                minNum = min(minNum, matrix[i][j]);
            }
            s.insert(minNum);
        }
        vector<int> result;
        for (int j = 0; j < n; j++) {
            int maxNum = matrix[0][j];
            for (int i = 1; i < m; i++) {
                maxNum = max(maxNum, matrix[i][j]);
            }
            if (s.find(maxNum) != s.end()) {
                result.push_back(maxNum);
            }
        }
        return result;
    }
};