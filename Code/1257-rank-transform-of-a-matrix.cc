class Solution {
    int find(vector<int> &root, int x) {
        if (root[x] != x) 
            root[x] = find(root, root[x]);
        return root[x];
    }
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[matrix[i][j]].push_back(i * n + j);
            }
        }
        
        vector<int> rank(m + n, 0);
        
        for (auto &it : mp) {
            vector<int> root(m + n, 0);
            // iota: Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value.
            iota(begin(root), end(root), 0);
            
            auto &v = it.second;
            for (auto &a : v) {
                int i = a / n;
                int j = a % n;
                int root1 = find(root, i);
                int root2 = find(root, j + m);
                root[root1] = root2;
                rank[root2] = max(rank[root1], rank[root2]);
            }
            
            auto rank2 = rank;
            for (auto &a : v) {
                int i = a / n;
                int j = a % n;
                int r = find(root, j + m);
                matrix[i][j] = rank[r] + 1;
                rank2[i] = rank[r] + 1;
                rank2[j + m] = rank[r] + 1;
            }
            
            rank = move(rank2);
        }
        
        return matrix;
    }
};