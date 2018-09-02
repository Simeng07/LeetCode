class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int result = 0;
        int cheapest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            result = max(result, prices[i] - cheapest);
            cheapest = min(cheapest, prices[i]);
        }
        return result;
    }
};