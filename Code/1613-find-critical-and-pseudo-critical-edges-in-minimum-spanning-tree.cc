class Solution {
    int root[101];
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<vector<int>> result(2, vector<int>());
        // return result;
        vector<int> special;
        int minWeight = kruskal(n, edges, special, true);
        for (int i = 0; i < edges.size(); i++) {
            int tmpWeight = kruskal(n, edges, edges[i], true); // remove special
            if (tmpWeight != minWeight) {
                result[0].push_back(edges[i][3]);
            } else {
                tmpWeight = kruskal(n, edges, edges[i], false);
                if (tmpWeight == minWeight) {
                    result[1].push_back(edges[i][3]);
                }
            }
        }
        return result;
    }
    
    int kruskal(int n, vector<vector<int>>& edges, vector<int>& special, bool remove) {
        memset(root, -1, sizeof(root));
        int weight = 0;
        if (special.size() == 4 && !remove) {
            root[special[0]] = special[0];
            root[special[1]] = special[0];
            weight = special[2];
        }
        for (int i = 0; i < edges.size(); i++) {
            if (special.size() == 4 && edges[i][0] == special[0] && edges[i][1] == special[1]) {
                continue;
            }
            int roota = getOrigin(edges[i][0]);
            int rootb = getOrigin(edges[i][1]);
            if (roota == rootb) {
                if (roota != -1) {  // 3 3
                    continue;
                } else {  // -1 -1
                    root[edges[i][0]] = edges[i][0];
                    root[edges[i][1]] = edges[i][0];
                }
            } else if (roota == -1 && rootb != -1) {  // -1 3
                root[edges[i][0]] = edges[i][1];
            } else if (roota != -1 && rootb == -1) {  // 3 -1
                root[edges[i][1]] = edges[i][0];
            } else {  // 3 4
                root[roota] = edges[i][1];
            }
            weight += edges[i][2];
        }
        return weight;
    }
    
    int getOrigin(int i) {
        while (root[i] != -1 && root[i] != i) {
            i = root[i];
        }
        return root[i];
    }
};