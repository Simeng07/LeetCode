class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    result += 1;
                    // "&", not ","
                    for (int k = 1; i + k < matrix.size() && j + k < matrix[0].size(); k++) {
                        bool findError = false;
                        for (int l = 0; l <= k; l++) {
                            if (matrix[i + l][j + k] != 1 || matrix[i + k][j + l] != 1) {
                                findError = true;
                                break;
                            }
                        }
                        if (!findError) {
                            result += 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};