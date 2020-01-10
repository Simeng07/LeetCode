class Solution {
    int result = INT_MAX;
    unordered_map<string, int> umap;
public:
    int tilingRectangle(int n, int m) {
        if (m == n) {
            return 1;
        }
        if (m % n == 0 || n % m == 0) {
            return max(m / n, n / m);
        }
        
        vector<int> v(n, 0);
        helper(v, m, n, 0);
        return result;
    }
    
    void helper(vector<int> &v, int m, int n, int current) {
        if (current >= result) {
            return;
        }
        
        int index = 0, count = m;
        for (int i = 0; i < n; i++) {
            if (v[i] < count) {
                count = v[i];
                index = i;
            }
        }
        
        if (count == m) {
            result = min(result, current);
            return;
        }
        
        // only handle one left-top corner a time
        for (int i = min(m + 1 - count, n - index); i > 0; i--) {
            bool canPaint = true;
            for (int j = 0; j < i; j++) {
                if (v[index + j] + i > m) {
                    canPaint = false;
                    break;
                }
            }
            if (canPaint) {
                for (int j = 0; j < i; j++) {
                    v[index + j] += i;
                }
                // backtracking
                helper(v, m, n, current + 1);
                for (int j = 0; j < i; j++) {
                    v[index + j] -= i;
                }
            }
        }
    }
};