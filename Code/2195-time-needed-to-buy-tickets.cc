class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target = tickets[k];
        int result = 0;
        for (int i = 0; i < tickets.size(); i++) {
            result += min(i <= k ? target : target - 1, tickets[i]);
        }
        return result;
    }
};