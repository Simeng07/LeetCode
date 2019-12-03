class Solution {
    int dp[101][101] = {0};
    int resultdp[101][101];
public:
    int palindromePartition(string s, int k) {
        if (s.size() == k) {
            return 0;
        }
        int size = s.size();
        for (int i = 2; i <= size; i++) {
            for (int j = 0; j < size; j++) {
                if (j + i <= size) {
                    dp[j][i] = dp[j + 1][i - 2] + (s[j] == s[j + i - 1] ? 0 : 1);
                }
            }
        }
        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                resultdp[i][j] = -1;
            }
        }
        return helper(0, k, s);
    }
    
    int helper(int index, int k, string &s) {
        if (resultdp[index][k] >= 0) {
            return resultdp[index][k];
        }
        if (k == 1) {
            return dp[index][s.size() - index];
        }
        int result = s.size() - index;
        for (int i = index + 1; i + k - 1 <= s.size(); i++) {
            result = min(result, helper(i, k - 1, s) + dp[index][i - index]);
        }
        resultdp[index][k] = result;
        // cout << index << " " << k << " " << result << endl;
        return result;
    }
};