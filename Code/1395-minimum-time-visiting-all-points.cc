class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 0;
        }
        int result = 0;
        for (int i = 1; i < points.size(); i++) {
            result += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return result;
    }
};