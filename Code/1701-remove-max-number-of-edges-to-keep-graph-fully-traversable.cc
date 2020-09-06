class Solution {
    int typeCount[3] = {0};
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> unionFind(2, vector<int>(n + 1, 0));
        
        // add all type3 edges into type1
        for (auto &edge : edges) {
            int type = edge[0], v1 = edge[1], v2 = edge[2];
            if (type == 3) {
                uf(3, v1, v2, unionFind);
            }
        }
        
        // add all type3 edges into type1
        unionFind[1].insert(unionFind[1].begin(), unionFind[0].begin(), unionFind[0].end());
        
        // add all type1 & type2 edges
        for (auto &edge : edges) {
            int type = edge[0], v1 = edge[1], v2 = edge[2];
            if (type == 1 || type == 2) {
                uf(type, v1, v2, unionFind);
            }
        }
        
        if (typeCount[0] + typeCount[2] != n - 1 || typeCount[1] + typeCount[2] != n - 1) {
            return -1;
        }
        return edges.size() - (typeCount[0] + typeCount[1] + typeCount[2]);
    }
    
    void uf(int type, int v1, int v2, vector<vector<int>> &unionFind) {
        int vType = (type == 3 ? 1 : type) - 1;
        if (unionFind[vType][v1] == 0 && unionFind[vType][v2] == 0) {
            unionFind[vType][v1] = v1;
            unionFind[vType][v2] = v1;
        } else if (unionFind[vType][v1] == 0 && unionFind[vType][v2] != 0) {
            unionFind[vType][v1] = unionFind[vType][v2];
        } else if (unionFind[vType][v1] != 0 && unionFind[vType][v2] == 0) {
            unionFind[vType][v2] = unionFind[vType][v1];
        } else {
            if (unionFind[vType][v1] != unionFind[vType][v2]) {
                int v1root = v1;
                while (unionFind[vType][v1root] != v1root) {
                    v1root = unionFind[vType][v1root];
                }
                int v2root = v2;
                while (unionFind[vType][v2root] != v2root) {
                    v2root = unionFind[vType][v2root];
                }
                if (v1root != v2root) {
                    unionFind[vType][v1root] = v2root;
                } else {
                    return;
                }
            } else {
                return;
            }
        }
        typeCount[type - 1]++;
    }
};