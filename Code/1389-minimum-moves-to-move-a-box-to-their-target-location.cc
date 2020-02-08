class Solution {
    int status[21][21] = {0};
    int diff[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int minPushBox(vector<vector<char>>& grid) {
        int S, B, T;
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, unordered_set<int>> has;
        unordered_map<int, unordered_set<int>> current;
        unordered_map<int, unordered_set<int>> next;
        // find SBT
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    S = i * 100 + j;
                }
                if (grid[i][j] == 'B') {
                    B = i * 100 + j;
                }
                if (grid[i][j] == 'T') {
                    T = i * 100 + j;
                }
            }
        }
        current[B].insert(S);
        int index = 1;
        int result = 0;
        while (current.size() != 0) {
            for (auto it = current.begin(); it != current.end(); ++it) {
                // current position
                int b = it->first;
                int i = b / 100, j = b % 100;
                if (b == T) {
                    return result;
                }
                status[i][j] = -1;
                unordered_set<int> &s = it->second;
                for (auto ss : s) {
                    // former position, same as person position when pushing the box to current position
                    has[b].insert(ss);
                    color(grid, ss, index);
                }
                for (int di = 0; di < 4; di++) {
                    if (i + diff[di][0] >= 0 && j + diff[di][1] >= 0 && i + diff[di][0] < m && j + diff[di][1] < n // check desitination
                        && grid[i + diff[di][0]][j + diff[di][1]] != '#' // not wall
                        && i - diff[di][0] >= 0 && j - diff[di][1] >= 0 && i - diff[di][0] < m && j - diff[di][1] < n // check pusher's position
                        && status[i - diff[di][0]][j - diff[di][1]] == index) { // whether pusher can go there
                        int nindex = (i + diff[di][0]) * 100 + j + diff[di][1];
                        if (has.find(nindex) == has.end() || has[nindex].find(b) == has[nindex].end()) {
                            next[nindex].insert(b);
                        }
                    }
                }
                status[i][j] = index;
                index++;
            }
            result++;
            current = next;
            next.clear();
        }
        return -1;
    }
    
    void color(vector<vector<char>>& grid, int s, int index) {
        int i = s / 100, j = s % 100;
        if (status[i][j] == index || status[i][j] == -1 || grid[i][j] == '#') {
            return;
        }
        status[i][j] = index;
        for (int di = 0; di < 4; di++) {
            if (i + diff[di][0] >= 0 && j + diff[di][1] >= 0 && i + diff[di][0] < grid.size() && j + diff[di][1] < grid[0].size()) {
                int nindex = (i + diff[di][0]) * 100 + j + diff[di][1];
                color(grid, nindex, index);
            }
        }
    }
};