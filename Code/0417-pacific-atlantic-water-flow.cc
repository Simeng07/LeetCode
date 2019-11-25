class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> answer;
        if (matrix.size() == 0) {
            return answer;
        }
        vector<vector<bool>> pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<bool>> atlantic(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int i = 0; i < matrix.size(); i++) {
            dfs(i, 0, matrix, pacific);
        }
        for (int i = 1; i < matrix[0].size(); i++) {
            dfs(0, i, matrix, pacific);
        }
        for (int i = 0; i < matrix.size(); i++) {
            dfs(i, matrix[0].size() - 1, matrix, atlantic);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            dfs(matrix.size() - 1, i, matrix, atlantic);
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    answer.push_back({i, j});
                }
            }
        }
        return answer;
    }
private:
    void dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& flow) {
        if (flow[row][col]) {
            return;
        }
        flow[row][col] = true;
        int height(matrix[row][col]);
        if (col != 0 && matrix[row][col - 1] >= height) {
            dfs(row, col - 1, matrix, flow);
        }
        if (row != 0 && matrix[row - 1][col] >= height) {
            dfs(row - 1, col, matrix, flow);
        }
        if (col != flow[0].size() - 1 && matrix[row][col + 1] >= height) {
            dfs(row, col + 1, matrix, flow);
        }
        if (row != flow.size() - 1 && matrix[row + 1][col] >= height) {
            dfs(row + 1, col, matrix, flow);
        }
    }
};