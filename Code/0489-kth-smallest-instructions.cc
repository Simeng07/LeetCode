class Solution {
    int dp[31][16] = {0};
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int m = destination[0];
        int n = destination[1];
        combinat(m + n, min(m, n)); // c(a, b), using dp
        
        string result = "";
        int count = 0;
        
        while (k >= 0) {
            // if move horizontally, there are hCount ways
            int hCount = dp[m + n - 1][min(m, n - 1)];
            
            if (hCount > k) {
                result += "H";
                n--;
                if (n == 0) {
                    for (int i = 0; i < m; i++) {
                        result += "V";
                    }
                    return result;
                }
            } else if (hCount < k) {
                result += "V";
                k -= hCount;
                m--;
                if (m == 0) {
                    for (int i = 0; i < n; i++) {
                        result += "H";
                    }
                    return result;
                }
            } else {
                result += "H";
                n--;
                for (int i = 0; i < m; i++) {
                    result += "V";
                }
                for (int i = 0; i < n; i++) {
                    result += "H";
                }
                return result;
            }
        }
        
        return result;
    }
    
    void combinat(int m, int n) {
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= i && j <= n; j++)
                if (i == j || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
};