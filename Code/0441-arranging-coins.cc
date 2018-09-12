class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) {
            return 0;
        }
        int row = 1;
        while (n - row >= 0) {
            n -= row;
            row++;
        }
        return row - 1;
    }
};