class Solution {
    unordered_map<int, unordered_set<int>> paths;
    bool has[17] = {false};
    int diameter = 0;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> result(n - 1, 0);
        for (auto &edge : edges) {
            paths[edge[0]].insert(edge[1]);
            paths[edge[1]].insert(edge[0]);
        }
        int allNodeMask = (1 << n) - 1;
        for (int i = 1; i <= allNodeMask; i++) {
            int oneCount = __builtin_popcount(i);
            if (oneCount == 1 || oneCount > n) {
                continue;
            }
            
            int distance = countDistance(i, n);
            if (distance != 0) {
                result[distance - 1]++;
            }
        }
        return result;
    }
    
    int countDistance(int mask, int n) {
        memset(has, false, sizeof(has));
        diameter = 0;
        
        int root = 1;
        while (true) {
            if (mask & (1 << (root - 1))) {
                break;
            }
            root++;
        }
        
        has[root] = true;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto node : paths[top]) {
                if (!has[node] && (mask & (1 << (node - 1)))) {
                    q.push(node);
                    has[node] = true;
                }
            }
        }
        
        // check if it is a tree
        for (int i = 1; i <= n; i++) {
            if (mask & (1 << (i - 1)) && !has[i]) {
                return 0;
            }
        }
        
        getDepth(mask, root, -1);
        
        return diameter;
    }
    
    int getDepth(int mask, int root, int last){
        vector<int> depthVector;
        
        for (auto node : paths[root]) {
            if (node != last && (mask & (1 << (node - 1)))) {
                int depth = 1 + getDepth(mask, node, root);
                depthVector.push_back(depth);
            }
        }
        
        if (depthVector.size() == 0) {
            return 0;
        }
        
        sort(depthVector.begin(), depthVector.end(), greater<int>());
        
        int maxDiameter = 0;
        for (int i = 0; i < min(2, (int)depthVector.size()); i++) {
            maxDiameter += depthVector[i];
        }
        
        if (maxDiameter > diameter) {
            diameter = maxDiameter;
        }
        
        return depthVector[0];
    }
};