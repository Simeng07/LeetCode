class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for (int i = 0; i < m; i++) {
            int obs = n;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '.') {
                    // empty
                    continue;
                }
                if (box[i][j] == '*') {
                    // obstacle 
                    obs = j;
                    continue;
                }
                // stone, can not fall
                if (obs - 1 == j) {
                    obs = j;
                    continue;
                }
                // stone, can fall
                if (box[i][obs - 1] == '.') {
                    box[i][obs - 1] = '#';
                    obs = obs - 1;
                    box[i][j] = '.';
                }
            }
        }
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = box[i][j];
            }
        }
        return result;
    }
};