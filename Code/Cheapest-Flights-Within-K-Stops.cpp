class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        unordered_map<int, vector<pair<int, int> > > map;
        for (auto flight : flights) {
            map[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<vector<int> > queue;
        
        queue.push({src, 0, 0});  // index, n步, n元
        
        int result = INT_MAX;
        bool find = false;
        
        while (!queue.empty()) {
            vector<int> current = queue.front();
            queue.pop();
            
            if (current[1] > K + 1) {
                break;  // 广度优先，一个超过了K+1，那么所有的都超过了
            }
            
            if (current[0] == dst) {
                result = min(result, current[2]);
                find = true;
                continue;
            }
            
            for (auto next : map[current[0]]) {
                if (current[2] + next.second < result) {
                    queue.push({next.first, current[1] + 1, current[2] + next.second});
                }
            }
        }
        
        return find ? result : -1;
    }
};