class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        if (coins[0] != 1) {
            return 1;
        }
        int max = 2;
        for (int i = 1; i < coins.size(); i++) {
            if (coins[i] > max) {
                return max;
            }
            max += coins[i];
        }
        return max;
    }
};