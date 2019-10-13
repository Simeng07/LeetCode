class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        int m[8];
        fill(m, m + 8, -1);
        for (int i = 0; i < queens.size(); i++) {
            if (queens[i][0] == king[0]) {
                if (queens[i][1] < king[1]) {
                    if (m[3] == -1 || (queens[m[3]][1] < queens[i][1])) {
                        m[3] = i;
                    }
                } else {
                    if (m[4] == -1 || (queens[m[4]][1] > queens[i][1])) {
                        m[4] = i;
                    }
                }
            }
            if (queens[i][1] == king[1]) {
                if (queens[i][0] < king[0]) {
                    if (m[1] == -1 || (queens[m[1]][0] < queens[i][0])) {
                        m[1] = i;
                    }
                } else {
                    if (m[6] == -1 || (queens[m[6]][0] > queens[i][0])) {
                        m[6] = i;
                    }
                }
            }
            if (queens[i][0] - queens[i][1] == king[0] - king[1]) {
                if (queens[i][0] < king[0]) {
                    if (m[0] == -1 || (queens[m[0]][0] < queens[i][0])) {
                        m[0] = i;
                    }
                } else {
                    if (m[7] == -1 || (queens[m[7]][0] > queens[i][0])) {
                        m[7] = i;
                    }
                }
            }
            if (queens[i][0] + queens[i][1] == king[0] + king[1]) {
                if (queens[i][0] < king[0]) {
                    if (m[2] == -1 || (queens[m[2]][0] < queens[i][0])) {
                        m[2] = i;
                    }
                } else {
                    if (m[5] == -1 || (queens[m[5]][0] > queens[i][0])) {
                        m[5] = i;
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            if (m[i] != -1) {
                result.push_back(queens[m[i]]);
            }
        }
        return result;
    }
};