class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size();
        int column = dungeon[0].size();
    
        // solution could be one dimention
        vector<vector<int> > solution;
        for (int i = row - 1; i >= 0; i--) {
            vector<int> rowv;
            for (int j = column - 1; j >= 0; j--) {
                int num;
                if (i == row - 1 && j == column - 1) {
                    num = (dungeon[i][j])*-1 + 1;
                } else {
                    if (i == row - 1) {
                        num = (dungeon[i][j])*-1 + rowv[column - j - 2];
                    }
                    else if (j == column - 1) {
                        num = (dungeon[i][j])*-1 + solution[row - i - 2][column - j - 1];
                    }
                    else {
                        int num1 = (dungeon[i][j])*-1 + rowv[column - j - 2];
                        int num2 = (dungeon[i][j])*-1 + solution[row - i - 2][column - j - 1];
                        num = (num1 > num2 ? num2 : num1);
                    }
                }
                rowv.push_back(num > 1 ? num : 1);
            }
            solution.push_back(rowv);
        }
        return solution[row-1][column-1];
    }
};