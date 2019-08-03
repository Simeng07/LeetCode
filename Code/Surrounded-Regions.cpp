class Solution {
    char replace = 'K';
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                helper(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                helper(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                helper(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                helper(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == replace) {
                    board[i][j] = 'O';
                }
            }
        }
        
        return;
    }
    
    void helper(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        
        board[i][j] = replace;
        
        if (i - 1 >= 0) {
            if (board[i - 1][j] == 'O') {
                helper(board, i - 1, j);
            }
        }
        if (i + 1 < m) {
            if (board[i + 1][j] == 'O') {
                helper(board, i + 1, j);
            }
        }
        if (j - 1 >= 0) {
            if (board[i][j - 1] == 'O') {
                helper(board, i, j - 1);
            }
        }
        if (j + 1 < n) {
            if (board[i][j + 1] == 'O') {
                helper(board, i, j + 1);
            }
        }
    }
};