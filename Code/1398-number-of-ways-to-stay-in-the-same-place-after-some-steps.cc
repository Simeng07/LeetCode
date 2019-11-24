class Solution {
public:
    int numWays(int steps, int arrLen) {
        int pos[502] = {0};
        pos[0] = 1;
        for (int i = 0; i < steps; i++) {
            int lastOne = pos[0];
            for (int j = 0; j <= i + 1 && j < arrLen; j++) {
                int tmp = 0;
                if (j > 0) {
                    tmp += lastOne;
                    tmp %= 1000000007;
                }
                tmp += pos[j];
                tmp %= 1000000007;
                if (j + 1 < arrLen && j + 1 <= steps) {
                    tmp += pos[j + 1];
                    tmp %= 1000000007;
                }
                lastOne = pos[j];
                pos[j] = tmp;
            }
        }
        return pos[0];
    }
};