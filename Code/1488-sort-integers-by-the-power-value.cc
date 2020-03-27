class Solution {
    int dp[1000000] = {0};
public:
    int getKth(int lo, int hi, int k) {
        vector<int> v(hi - lo + 1);
        for (int i = 0; i < hi - lo + 1; i++) {
            v[i] = lo + i;
        }
        sort(v.begin(), v.end(), [this](int a, int b){
            int pa = p(a);
            int pb = p(b);
            if (pa == pb) {
                return a < b;
            } else {
                return pa < pb;
            }
        });
        return v[k - 1];
    }
    
    int p(int n) {
        if (n == 1) {
            return 0;
        }
        if (dp[n] == 0) {
            int next = n % 2 == 0 ? n / 2 : 3 * n + 1;
            dp[n] = p(next) + 1;
        }
        return dp[n];
    }
};