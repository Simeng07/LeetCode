class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        if (M == 0) {
            return 0;
        }
        
        unordered_map<int, vector<pair<int, int> > > map; // 网络图
        int done[N];  // 01标记是否已完成
        memset(done, 0, sizeof(done));
        int remain[N]; // 标记到达该顶点后，剩余步数
        memset(remain, -1, sizeof(remain));
        remain[0] = M;
        
        // 初始化网络图
        for (int i = 0; i < edges.size(); i++) {
            map[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            map[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        // 还未进行的顶点，按照第一个值（剩余步数）从大到小排序
        priority_queue<pair<int, int> > queue;
        queue.push({M, 0});
        
        while(!queue.empty()) {
            pair<int, int> current = queue.top();
            queue.pop();
            // current.second: 当前顶点index
            // current.first: 当前剩余步数
            if (done[current.second] == 0) {
                done[current.second] = 1;
                for (auto next : map[current.second]) {
                    int nextNode = next.first;
                    int totalStep = next.second;
                    int remainStep = current.first;
                    int nextRemain = remainStep - totalStep - 1;
                    remain[nextNode] = max(remain[nextNode], nextRemain);
                    if (remain[nextNode] >= 0) {
                        queue.push({nextRemain, nextNode});
                    }
                }
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            result += min(edges[i][2], 
                              (remain[edges[i][0]] > 0 ? remain[edges[i][0]] : 0) + 
                              (remain[edges[i][1]] > 0 ? remain[edges[i][1]] : 0));
        }
        
        for (int i = 0; i < N; i++) {
            result += done[i];
        }
        
        return result;
    }
};