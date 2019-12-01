class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int a = 1;
        int g[3][3] = {0};
        for (auto &move : moves) {
            g[move[0]][move[1]] = a;
            if ((g[0][0] == a && g[0][1] == a && g[0][2] == a)
                || (g[1][0] == a && g[1][1] == a && g[1][2] == a)
                || (g[2][0] == a && g[2][1] == a && g[2][2] == a)
                || (g[0][0] == a && g[1][0] == a && g[2][0] == a)
                || (g[0][1] == a && g[1][1] == a && g[2][1] == a)
                || (g[0][2] == a && g[1][2] == a && g[2][2] == a)
                || (g[0][0] == a && g[1][1] == a && g[2][2] == a)
                || (g[0][2] == a && g[1][1] == a && g[2][0] == a)) {
                if (a == 1) {
                    return "A";
                } else {
                    return "B";
                }
            }
            a = 3 - a;
        }
        if (moves.size() == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }
};