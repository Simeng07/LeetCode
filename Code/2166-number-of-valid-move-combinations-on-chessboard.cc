class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int result = 0;
        for (int i = 0; i < positions.size(); i++) {
            for (int j = 0; j < positions[0].size(); j++) {
                positions[i][j]--;
            }
        }
        for (int i = 0; i < 64; i++) {
            if (!check(positions[0][0], positions[0][1], i / 8, i % 8, pieces[0])) {
                continue;
            }
            if (pieces.size() > 1) {
                for (int j = 0; j < 64; j++) {
                    if (!check(positions[1][0], positions[1][1], j / 8, j % 8, pieces[1])) {
                        continue;
                    }
                    if (pieces.size() > 2) {
                        for (int k = 0; k < 64; k++) {
                            if (!check(positions[2][0], positions[2][1], k / 8, k % 8, pieces[2])) {
                                continue;
                            }
                            if (pieces.size() > 3) {
                                for (int l = 0; l < 64; l++) {
                                    if (!check(positions[3][0], positions[3][1], l / 8, l % 8, pieces[3])) {
                                        continue;
                                    }
                                    vector<int> tmp = {i, j, k, l};
                                    if (helper(pieces, positions, tmp)) {
                                        result++;
                                    }
                                }
                            } else {
                                vector<int> tmp = {i, j, k};
                                if (helper(pieces, positions, tmp)) {
                                    result++;
                                }
                            }
                        }
                    } else {
                        vector<int> tmp = {i, j};
                        if (helper(pieces, positions, tmp)) {
                            result++;
                        }
                    }
                }
            } else {
                vector<int> tmp = {i};
                if (helper(pieces, positions, tmp)) {
                    result++;
                }
            }
        }
        return result;
    }
    
    bool helper(vector<string>& pieces, vector<vector<int>> positions, vector<int>& stops) {
        int n = pieces.size();
        int dir[4][2] = {0};
        for (int i = 0; i < n; i++) {
            dir[i][0] = stops[i] / 8 == positions[i][0] ? 0 : (stops[i] / 8 - positions[i][0] > 0 ? 1 : -1);
            dir[i][1] = stops[i] % 8 == positions[i][1] ? 0 : (stops[i] % 8 - positions[i][1] > 0 ? 1 : -1);
        }
        for (int k = 0; k < 7; k++) {
            for (int i = 0; i < n; i++) {
                if (positions[i][0] == stops[i] / 8 && positions[i][1] == stops[i] % 8) {
                    continue;
                }
                if (positions[i][0] + dir[i][0] >= 0 && positions[i][0] + dir[i][0] < 8 && positions[i][1] + dir[i][1] >= 0 && positions[i][1] + dir[i][1] < 8) {
                    positions[i][0] += dir[i][0];
                    positions[i][1] += dir[i][1];
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (positions[i][0] == positions[j][0] && positions[i][1] == positions[j][1]) {
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
    
    bool check(int x0, int y0, int x1, int y1, string piece) {
        if (piece == "rook") {
            return (x0 == x1 || y0 == y1);
        }
        if (piece == "bishop") {
            return ((x1 - x0 == y1 - y0) || (x1 - x0 == y0 - y1));
        } 
        return ((x0 == x1 || y0 == y1) || ((x1 - x0 == y1 - y0) || (x1 - x0 == y0 - y1)));
    }
};