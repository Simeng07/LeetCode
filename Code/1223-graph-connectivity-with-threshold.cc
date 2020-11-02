class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if (threshold == 0) {
            vector<bool> result(queries.size());
            for (int i = 0; i < queries.size(); i++) {
                result[i] = true;
            }
            return result;
        }
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                if (parent[j] == j) {
                    parent[j] = parent[i];
                } else {
                    if (parent[j] > parent[i]) {
                        parent[parent[j]] = parent[i];
                    } else if (parent[j] < parent[i]) {
                        parent[parent[i]] = parent[j];
                    }
                }
            }
        }
        
        vector<bool> result;
        for (auto &query : queries) {
            int a = query[0];
            int b = query[1];
            int pa = parent[a];
            while (pa != a) {
                a = pa;
                pa = parent[pa];
            }
            int pb = parent[b];
            while (pb != b) {
                b = pb;
                pb = parent[pb];
            }
            result.push_back(pa == pb);
        }
        
        return result;
    }
};