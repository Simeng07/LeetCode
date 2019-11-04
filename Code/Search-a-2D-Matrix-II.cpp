class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        if (matrix[0][0] > target) return false;
        if (matrix[matrix.size()-1][matrix[0].size()-1] < target) return false;
        int i = 0, j = matrix[0].size()-1;
        while(i <= matrix.size()-1 && j >= 0) {
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};