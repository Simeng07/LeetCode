class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins - costs[i] >= 0) {
                result++;
                coins -= costs[i];
            } else {
                return result;
            }
        }
        return result;
    }
};