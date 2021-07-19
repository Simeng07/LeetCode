class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<pair<long long, int>> left(n);
        vector<pair<long long, int>> right(n);
        vector<long long> tmpLine(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmpLine[j] = points[i][j] + (i == 0 ? 0 : max(left[j].first - (j - left[j].second), right[j].first - (right[j].second - j)));
                if (j == 0) {
                    left[0] = {tmpLine[0], 0};
                } else {
                    if (tmpLine[j] > left[j - 1].first - (j - left[j - 1].second)) {
                        left[j] = {tmpLine[j], j};
                    } else {
                        left[j] = left[j - 1];
                    }
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) {
                    right[n - 1] = {tmpLine[n - 1], n - 1};
                } else {
                    if (tmpLine[j] > right[j + 1].first - (right[j + 1].second - j)) {
                        right[j] = {tmpLine[j], j};
                    } else {
                        right[j] = right[j + 1];
                    }
                }
            }
        }
        
        long long result = INT_MIN;
        for (int i = 0; i < n; i++) {
            result = max(result, tmpLine[i]);
        }
        
        return result;
    }
};