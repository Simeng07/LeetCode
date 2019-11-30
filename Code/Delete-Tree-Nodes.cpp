class Solution {
    unordered_map<int, unordered_set<int>> m;
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for (int i = 0; i < nodes; i++) {
            m[parent[i]].insert(i);
        }
        pair<int, int> result = helper(0, value);
        if (result.first == 0) {
            return 0;
        }
        return result.second;
    }
    
    // helper返回的是{元素总和，元素个数}
    pair<int, int> helper(int i, vector<int>& value) {
        int sum = value[i], count = 1;
        for (auto n : m[i]) {
            pair<int, int> p = helper(n, value);
            if (p.first == 0) {
                continue;
            }
            sum += p.first;
            count += p.second;
        }
        if (sum == 0) {
            return {0, 0};
        }
        return make_pair(sum, count);
    }
};