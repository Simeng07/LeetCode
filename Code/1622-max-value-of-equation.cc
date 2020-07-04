class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        int result = INT_MIN;
        for (auto &point : points) {
            while (!q.empty() && q.top().second < point[0] - k) {
                q.pop();
            }
            if (!q.empty()) {
                result = max(result, q.top().first + point[0] + point[1]);
            }
            q.push(make_pair(point[1] - point[0], point[0]));
        }
        return result;
    }
};