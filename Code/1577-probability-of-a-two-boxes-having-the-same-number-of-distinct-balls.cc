class Solution {
    double result = 0;
    int total;
public:
    double getProbability(vector<int>& balls) {
        for (auto ball : balls) {
            total += ball;
        }
        helper(balls, 1, 0, 0, 0, 0, 0);
        return result;
    }
    
    void helper(vector<int>& balls, double prop, int index, int firstCount, int firstKind, int secondCount, int secondKind) {
        if (index == balls.size()) {
            if (firstCount == secondCount && firstKind == secondKind) {
                result += prop;
            }
            return;
        }
        if (max(firstCount, secondCount) > total / 2) {
            return;
        }
        int currentCount = balls[index];
        for (int i = 0; i <= currentCount; i++) {
            if (total / 2 - firstCount < i || total / 2 - secondCount < currentCount - i) {
                continue;
            }
            double p = c(total / 2 - firstCount, i) * c(total / 2 - secondCount, currentCount - i) / c(total - firstCount - secondCount, currentCount);
            helper(balls, prop * p, index + 1, firstCount + i, firstKind + (i == 0 ? 0 : 1), secondCount + currentCount - i, secondKind + (i == currentCount ? 0 : 1));
        }
    }
    
    double c(int a, int b) {
        double result = 1;
        if (b == 0 || b == a) {
            return 1;
        }
        for (int i = 0; i < b; i++) {
            result *= (a - i);
            result /= (b - i);
        }
        return result;
    }
};