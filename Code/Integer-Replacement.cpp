class Solution {
public:
    int integerReplacement(int n) {
        int result = 0;
        long ln = n;
        while (ln != 1) {
            if (ln & 1) {
                if (ln & 2 && ln != 3) {
                    ln += 1;
                } else {
                    ln -= 1;
                }
            } else {
                ln >>= 1;
            }
            result += 1;
        }
        return result;
    }
};