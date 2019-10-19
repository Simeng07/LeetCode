class Solution {
    double result = 0.0;
    double p[1001][1001] = {};
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = (int)prob.size();
        p[0][0] = 1 - prob[0];
        p[0][1] = prob[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i + 1; j++) {
                p[i][j] += p[i - 1][j] * (1 - prob[i]) + (j > 0 ? p[i - 1][j - 1] * prob[i] : 0);
            }
        }
        return p[n - 1][target];
    }
};