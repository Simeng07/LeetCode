class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        double p = 1;
        double q = (int)(num / 2);
        double middle = (int)((p + q) / 2);
        if (num / p == p || num / q == q || num / middle == middle) {
            return true;
        }
        while (p < q - 1) {
            if (num / middle < middle) {
                q = middle;
            }
            if (num / middle > middle) {
                p = middle;
            }
            if (num / middle == middle) {
                
                return true;
            }
            middle = (int)((p + q) / 2);
        }
        return (num / p == p || num / q == q);
    }
};