class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        if (x0 == x1) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != x0) {
                    return false;
                }
            }
            return true;
        }
        double k = (double)(y1 - y0) / (x1 - x0);
        for (int i = 2; i < coordinates.size(); i++) {
            double kk = (double)(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
            if (kk != k) {
                return false;
            }
        }
        return true;
    }
};