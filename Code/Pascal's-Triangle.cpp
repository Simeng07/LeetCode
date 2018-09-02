class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) {
            return result;
        }
        vector<int> r0 = {1};
        result.push_back(r0);
        for (int i = 1; i < numRows; i++) {
            vector<int> ri = {1};
            for (int j = 0; j < result[i - 1].size() - 1; j++) {
                ri.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            ri.push_back(1);
            result.push_back(ri);
        }
        return result;
    }
};