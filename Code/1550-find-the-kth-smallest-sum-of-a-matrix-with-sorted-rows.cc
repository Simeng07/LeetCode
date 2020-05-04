class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> current = mat[0];
        for (int i = 1; i < mat.size(); i++) {
            vector<int> tmp(current.size() * mat[i].size(), 0);
            for (int j = 0; j < mat[i].size(); j++) {
                for (int k = 0; k < current.size(); k++) {
                    tmp[k + j * (current.size())] = current[k] + mat[i][j];
                }
            }
            sort(tmp.begin(), tmp.end());
            tmp.resize(min(k, (int)tmp.size()));
            current = tmp; 
        }
        return current[k - 1];
    }
};