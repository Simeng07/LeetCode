class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) {
            return 0;
        }
        
        // earn most from left to right
        int *best = new int[size]{0};
        int cheapest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            best[i] = max(best[i - 1], prices[i] - cheapest);
            cheapest = min(cheapest, prices[i]);
        }
        
        // lose most from right to left
        int *worst = new int[size]{0};
        int highest = prices[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            worst[i] = min(worst[i + 1], prices[i] - highest);
            highest = max(highest, prices[i]);
        }
        
        int result = 0;
        
        for (int i = 1; i < size - 2; i++) {
            result = max(result, best[i] - worst[i + 1]);
        }
        
        // only one transactions
        result = max(result, best[size - 1]);
        result = max(result, -worst[0]);
        
        return result;
    }
};