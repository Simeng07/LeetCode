class Solution {
    // https://www.zhihu.com/question/24251545
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double recCenterX = ((double)x1 + x2) / 2;
        double recCenterY = ((double)y1 + y2) / 2;
        double cirCenterX = (x_center > recCenterX) ? (double)x_center : 2 * recCenterX - x_center;
        double cirCenterY = (y_center > recCenterY) ? (double)y_center : 2 * recCenterY - y_center;
        double vX = cirCenterX - recCenterX;
        double vY = cirCenterY - recCenterY;
        double hX = max(x1, x2) - recCenterX;
        double hY = max(y1, y2) - recCenterY;
        double uX = vX - hX;
        if (uX < 0) uX = 0;
        double uY = vY - hY;
        if (uY < 0) uY = 0;
        return (radius * radius >= uX * uX + uY * uY);
    }
};