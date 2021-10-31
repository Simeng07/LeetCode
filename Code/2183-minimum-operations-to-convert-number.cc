class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> m;
        queue<int> q;
        q.push(start);
        m[start] = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            int current = m[n];
            for (auto num : nums) {
                if (n + num == goal || n - num == goal || (n ^ num) == goal) {
                    return current + 1;
                }
                if (n + num >= 0 && n + num <= 1000) {
                    if (m.find(n + num) == m.end()) {
                        m[n + num] = current + 1;
                        q.push(n + num);
                    }
                }
                if (n - num >= 0 && n - num <= 1000) {
                    if (m.find(n - num) == m.end()) {
                        m[n - num] = current + 1;
                        q.push(n - num);
                    }
                }
                if ((n ^ num) >= 0 && (n ^ num) <= 1000) {
                    if (m.find(n ^ num) == m.end()) {
                        m[n ^ num] = current + 1;
                        q.push(n ^ num);
                    }
                }
            }
        }
        return -1;
    }
};