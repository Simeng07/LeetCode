class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        int count = 0;
        int position = 1;
        while (true) {
            count++;
            position = position * 2 % (n - 1);
            if (position == 1) {
                return count;
            }
        }
        return count;
    }
};