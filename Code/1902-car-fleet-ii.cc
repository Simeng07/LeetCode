class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> s;
        vector<double> result(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty()) {
                int j = s.top();
                // 追不上，或者i在追上此车j时，此车已经追上了更右边的车
                if (cars[i][1] <= cars[j][1] 
                    || (result[j] > 0 
                        && 1.0 * (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]) >= result[j])) {
                    s.pop();
                } else {
                    break;
                }
            }
            if (!s.empty()) {
                result[i] = 1.0 * (cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]);
            }
            s.push(i);
        }
        return result;
    }
};