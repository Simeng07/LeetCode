class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (m == 1 || n == 1) {
            return mat;
        }
        
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j + i < m && j < n; j++) {
                tmp.push_back(mat[i + j][j]);
            }
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j + i < m && j < n; j++) {
                mat[i + j][j] = tmp[j];
            }
        }
        
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n && i < m; i++) {
                tmp.push_back(mat[i][i + j]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n && i < m; i++) {
                mat[i][i + j] = tmp[i];
            }
        }
        
        return mat;
    }
};