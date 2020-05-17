class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int result = 1;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                result = max(result, cal(i, j, r, points));
            }
        }
        return result;
    }
    
    int cal(int index1, int index2, double r, vector<vector<int>>& points) {
        double x1 = points[index1][0], y1 = points[index1][1], x2 = points[index2][0], y2 = points[index2][1];
        if (x1 == x2 && y1 == y2) {
            return 0;
        }
        double distance = dis(x1, y1, x2, y2);
        if (distance > 2 * r) {
            return 0;
        } else if (distance == 2 * r) {
            return count((x1 + x2) / 2, (y1 + y2) / 2, r, points);
        } else {
            double mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
            double middleDistance = sqrt((mx - x1) * (mx - x1) + (my - y1) * (my - y1));
            double h = sqrt(r * r - middleDistance * middleDistance);
            double c1x = mx + (y1 - my) * h / middleDistance;
            double c1y = my - (x1 - mx) * h / middleDistance;
            double c2x = mx - (y1 - my) * h / middleDistance;
            double c2y = my + (x1 - mx) * h / middleDistance;
            return max(count(c1x, c1y, r, points), count(c2x, c2y, r, points));
        }
    }
    
    int count(double x, double y, double r, vector<vector<int>>& points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            double x1 = points[i][0], y1 = points[i][1];
            double distance1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            double distance2 = r * r;
            if (distance1 - distance2 <= 1e-5) {
                result++;
            }
        }
        return result;
    }
    
    double dis(int x1, int y1, int x2, int y2) {
        return sqrt(double((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }
};