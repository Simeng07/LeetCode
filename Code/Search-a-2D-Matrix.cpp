class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        if (matrix.size() * matrix[0].size() == 1) return matrix[0][0]==target;
        if (matrix[0][0] > target) return false;
        if (matrix[matrix.size()-1][matrix[0].size()-1] < target) return false;
        return searchMatrix1(matrix, target, 1, matrix.size() * matrix[0].size());
    }
    
    int index2value(vector<vector<int> >& matrix, int index) {
        // convert index to ij
        int i = (index-1) / matrix[0].size();
        int j = (index-1) % matrix[0].size();
        return matrix[i][j];
    }
    
    // binary search
    bool searchMatrix1(vector<vector<int> >& matrix, int target, int a, int b) {
        if (a == b - 1) return (index2value(matrix, a) == target || index2value(matrix, b) == target);
        int tmp = index2value(matrix, (a+b)/2);
        if (tmp < target) return searchMatrix1(matrix, target, (a+b)/2, b);
        if (tmp > target) return searchMatrix1(matrix, target, a, (a+b)/2);
        return true;
    }
};