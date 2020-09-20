class Solution {
    int maxRightValue;
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        maxRightValue = (1 << (cost[0].size())) - 1;
        vector<vector<int>> dp(cost.size() + 1, vector<int>(maxRightValue + 1, -1));
        return helper(cost, 0, 0, dp);
    }
    
    int helper(vector<vector<int>>& cost, int leftIndex, int rightValue, vector<vector<int>> &dp) {
        if (dp[leftIndex][rightValue] != -1) {
            return dp[leftIndex][rightValue];
        }
        
        if (leftIndex >= cost.size()) {
            int result = 0;
            for (int i = 0; i < cost[0].size(); i++) {
                if ((rightValue & (1 << i)) == 0) {
                    // right nodes which are not connected
                    int tmpMin = INT_MAX;
                    for (int j = 0; j < cost.size(); j++) {
                        tmpMin = min(tmpMin, cost[j][i]);
                    }
                    result += tmpMin;
                }
            }
            dp[leftIndex][rightValue] = result;
            return result;
        }
        
        int result = INT_MAX;
        for (int i = 0; i < cost[0].size(); i++) {
            result = min(result, cost[leftIndex][i] + helper(cost, leftIndex + 1, (rightValue | (1 << i)), dp));
        }
        
        dp[leftIndex][rightValue] = result;
        return result;
    }
};