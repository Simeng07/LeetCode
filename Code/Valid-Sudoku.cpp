class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            int row = 0;
            int column = 0;
            int block = 0;
            for (int j = 0; j < 9; j++) {
                int rowValue = board[i][j] - '1';
                int columnValue = board[j][i] - '1';
                // 对于i来说，0-00,1-03,2-06,3-30,4-33,5-36,6-60,7-63,8-66
                // 对于j来说，0-00,1-01,2-02,3-10,4-11,5-12,6-20,7-21,8-22
                int blockValue = board[i/3*3 + j/3][i%3*3 + j%3] - '1'; 
                if (rowValue >=0 && (row & (1 << rowValue)) != 0
                    || columnValue >= 0 && (column & (1 << columnValue)) != 0
                    || blockValue >= 0 && (block & (1 << blockValue)) != 0)
                    return false;
                row |= rowValue >= 0 ? 1 << rowValue : 0;
                column |= columnValue >=0 ? 1 << columnValue : 0;
                block |= blockValue >= 0 ? 1 << blockValue : 0;
            }
        }
        return true;
    }
};