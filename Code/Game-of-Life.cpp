class Solution {
public:

    void gameOfLife(vector<vector<int> >& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = getAndSetNumer(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                board[i][j] %= 2;
    }
    
    int getOriginalNum(int n) {
        if (n == 2) return 1;
        if (n == 3) return 0;
        return n;
    }

    int getAndSetNumer(vector<vector<int> >& board, int i, int j) {
        int result = 0;
        if (i > 0) {
            if (j > 0) 
                result += getOriginalNum(board[i - 1][j - 1]);
            if (j < board[0].size() - 1) 
                result += getOriginalNum(board[i - 1][j + 1]);
            result += getOriginalNum(board[i - 1][j]);
        }
        if (i < board.size() - 1) {
            if (j > 0) 
                result += board[i + 1][j - 1];
            if (j < board[0].size() - 1) 
                result += board[i + 1][j + 1];
            result += board[i + 1][j];
        }
        if (j > 0) {
            result += getOriginalNum(board[i][j - 1]);
        }
        if (j < board[0].size() - 1) {
            result += board[i][j + 1];
        }
        // 1-0: 2
        // 0-1: 3
        if (board[i][j] == 1) {
            if (result == 2 || result == 3) return 1;
            return 2;
        } else {
            if (result == 3) return 3;
            return 0;
        }
    }
};