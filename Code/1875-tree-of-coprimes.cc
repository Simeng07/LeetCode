class Solution {
    vector<vector<int>> graph;
    stack<pair<int,int>> lasts[51];  // (level, index)
    vector<int> result;
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.resize(n);
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        result.resize(n);
        dfs(0, -1, 0, nums);
        return result;
    }
    
    void dfs(int node, int pre, int level, vector<int>& nums) {
        int re = -1, lev = -1;
        for(int i = 1; i <= 50; ++i) {
            // find the nearest(biggest level) coprime index
            if(lasts[i].size() && lasts[i].top().first > lev && __gcd(i, nums[node]) == 1) {
                re = lasts[i].top().second;
                lev = lasts[i].top().first;
            }
        }
        result[node] = re;
        for(int ne : graph[node]) {
            if(ne != pre) {
                lasts[nums[node]].push({level, node});
                dfs(ne, node, level + 1, nums);
                lasts[nums[node]].pop();
            }
        }
    }
};