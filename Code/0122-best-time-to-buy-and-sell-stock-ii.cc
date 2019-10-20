class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(0, prices[i] - prices[i - 1]);
        }
        return result;
    }
};