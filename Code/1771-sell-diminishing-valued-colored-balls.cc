class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int MOD = 1e9 + 7;
        long long result = 0;
        inventory.push_back(0);
        sort(inventory.begin(), inventory.end(), greater<int>());
        for (int i = 1; i < inventory.size(); i++) {
            long long count = (inventory[i - 1] - inventory[i]) * i;
            if (count <= orders) {
                orders -= count;
                long long patch = (long long)(inventory[i - 1] + inventory[i] + 1) * (inventory[i - 1] - inventory[i]) / 2;
                result += patch * i;
                result %= MOD;
                if (orders == 0) {
                    return result;
                }
            } else {
                long long wholeRow = orders / i;
                long long remain = orders % i;
                long long patch = (inventory[i - 1] + inventory[i - 1] - wholeRow + 1) * wholeRow / 2;
                result += patch * i;
                result %= MOD;
                result += remain * (inventory[i - 1] - wholeRow);
                result %= MOD;
                return result;
            }
        }
        return result;
    }
};