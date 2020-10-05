class Solution {
#define PI 3.14159265
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        if (points.size() <= 1) {
            return points.size();
        }
        
        int result = 1;
        int dup = 0;
        
        vector<double> v;
        for (auto &point : points) {
            if (point[1] == location[1] && point[0] == location[0]) {
                dup++;
            } else {
                double arctan = atan2(point[1] - location[1], point[0] - location[0]) * 180 / PI;
                v.push_back(arctan);
                if (arctan + 180 <= angle) {
                    v.push_back(arctan + 360);
                }
            }
        }
        sort(v.begin(), v.end());
        
        int begin = 0, end = 1, count = 1;
        
        while (begin <= end && end < v.size()) {
            if (v[end] - v[begin] <= angle) {
                count++;
                end++;
                result = max(result, count);
            } else {
                count--;
                begin++;
            }
        }
        
        return result + dup;
    }
};