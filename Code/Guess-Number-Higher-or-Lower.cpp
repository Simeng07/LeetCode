// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int p = 1, q = n;
        if (guess(p) == 0) {
            return p;
        }
        if (guess(q) == 0) {
            return q;
        }
        int middle = 1 + (n - 1) / 2;
        int gs = guess(middle);
        if (gs == 0) {
            return middle;
        }
        while (p < q) {
            if (gs == -1) {
                q = middle;
            } else if (gs == 1) {
                p = middle;
            } else {
                return middle;
            }
            middle = p + (q - p) / 2;
            gs = guess(middle);
        }
        return middle;
    }
};