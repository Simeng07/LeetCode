class Solution {
    unordered_map<int, unordered_set<int>> children;
    unordered_map<int, int> valueToNode;
    bool seen[100002] = {0};
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> result(n, 1);
        
        for (int i = 0; i < parents.size(); i++) {
            children[parents[i]].insert(i);
            valueToNode[nums[i]] = i;
        }
        
        if (valueToNode.find(1) == valueToNode.end()) {
            return result;
        }
        
        int node = valueToNode[1];
        int miss = 1;
        
        while (node >= 0) {
            dfs(node, nums);
            while (seen[miss]) {
                miss++;
            }
            result[node] = miss;
            node = parents[node];
        }
        
        return result;
    }
    
    void dfs(int node, vector<int>& nums) {
        if (!seen[nums[node]]) {
            for (auto it = children[node].begin(); it != children[node].end(); ++it) {
                dfs(*it, nums);
            }
            seen[nums[node]] = true;
        }
    }
};