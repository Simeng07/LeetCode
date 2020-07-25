class Solution {
    string dp[5001];
public:
    string largestNumber(vector<int>& cost, int target) {
        return helper(cost, target);
    }
    
    string helper(vector<int>& cost, int target) {
        if (dp[target] != "") {
            return dp[target];
        }
        if (target == 0) {
            return "";
        }
        // cout <<  target << endl;
        string tmpMax = "0";
        for (int i = 0; i < 9; i++) {
            if (target - cost[i] >= 0) {
                char left = '0' + (i + 1);
                string right;
                if (target - cost[i] == 0) {
                    right = "";
                } else {
                    right = helper(cost, target - cost[i]);
                }
                if (right == "0") {
                    // no way
                    continue;
                }
                string combine = left + right;
                if (combine.length() > tmpMax.length() || (combine.length() == tmpMax.length() && combine > tmpMax)) {
                    tmpMax = combine;
                }
            }
        }
        dp[target] = tmpMax;
        return dp[target];
    }
};