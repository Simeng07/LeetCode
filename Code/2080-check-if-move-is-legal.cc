class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char another;
        if (color == 'B') {
            another = 'W';
        } else {
            another = 'B';
        }
        int i = rMove, j = cMove;
        int m = board.size(), n = board[0].size();
        if (i + 2 < m && board[i + 1][j] == another) {
            i += 2;
            while (i < m) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i++;
            }
        }
        i = rMove, j = cMove;
        if (i - 2 >= 0 && board[i - 1][j] == another) {
            i -= 2;
            while (i >= 0) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i--;
            }
        }
        i = rMove, j = cMove;
        if (j + 2 < n && board[i][j + 1] == another) {
            j += 2;
            while (j < n) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                j++;
            }
        }
        i = rMove, j = cMove;
        if (j - 2 >= 0 && board[i][j - 1] == another) {
            j -= 2;
            while (j >= 0) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                j--;
            }
        }
        i = rMove, j = cMove;
        if (i + 2 < m && j + 2 < n && board[i + 1][j + 1] == another) {
            i += 2;
            j += 2;
            while (i < m && j < n) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i++;
                j++;
            }
        }
        i = rMove, j = cMove;
        if (i - 2 >= 0 && j + 2 < n && board[i - 1][j + 1] == another) {
            i -= 2;
            j += 2;
            while (i >= 0 && j < n) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i--;
                j++;
            }
        }
        i = rMove, j = cMove;
        if (i + 2 < m && j - 2 >= 0 && board[i + 1][j - 1] == another) {
            i += 2;
            j -= 2;
            while (i < m && j >= 0) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i++;
                j--;
            }
        }
        i = rMove, j = cMove;
        if (i - 2 >= 0 && j - 2 >= 0  && board[i - 1][j - 1] == another) {
            i -= 2;
            j -= 2;
            while (i >= 0 && j >= 0) {
                if (board[i][j] == color) {
                    return true;
                }
                if (board[i][j] == '.') {
                    break;
                }
                i--;
                j--;
            }
        }
        return false;
    }
};