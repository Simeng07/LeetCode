// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int p = 1;
        int q = n;
        int middle = p + (q - p) / 2;
        while (true) {
            if (p == middle) {
                return (isBadVersion(middle) ? p : q);
            }
            if (isBadVersion(middle)) {
                q = middle;
            } else {
                p = middle;
            }
            middle = p + (q - p) / 2;
        }
    }
};