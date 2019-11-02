class Solution {
    unordered_map<int, unordered_set<int>> m;
    unordered_map<int, unordered_map<int, int>> dp;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        for (auto &edge : edges) {
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        int result = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if ((it->second).size() == 1) {
                result = max(result, helper(it->first, it->first, edges));
            }
        }
        return result;
    }
    int helper(int currentIndex, int lastIndex, vector<vector<int>>& edges) {
        // cout << currentIndex <<" " << lastIndex << " ========" << endl;
        if (currentIndex >= edges.size()) {
            return 0;
        }
        if (dp[currentIndex][lastIndex] != 0) {
            return dp[currentIndex][lastIndex];
        }
        int tmp = 0;
        for (auto it = m[currentIndex].begin(); it != m[currentIndex].end(); ++it) {
            if (*it != lastIndex) {
                tmp = max(tmp, helper(*it, currentIndex, edges) + 1);
            }
        }
        dp[currentIndex][lastIndex] = tmp;
        // cout << currentIndex <<" " << lastIndex << " "<< tmp << endl;
        return tmp;
    }
};