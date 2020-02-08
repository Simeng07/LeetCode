class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = 360.0 * minutes / 60;
        double h = 360.0 * (hour % 12) / 12 + 30.0 * minutes / 60;
        double diff = abs(m - h);
        if (diff > 180) {
            return 360 - diff;
        }
        return diff;
    }
};