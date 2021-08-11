class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        vector<int> left(n), right(n), center(n);
        
        int i = 0, j = 0;
        while (i < n) {
            while (i - j >= 0 && i + j < n && s[i + j] == s[i - j]) {
                left[i + j] = max(left[i + j], j);
                right[i - j] = max(right[i - j], j);
                j++;
            }
            
            center[i] = --j;
            int k = 1;
            
            int jold = j;
            j = 0;
            
            while (k <= jold) {
                int mirror = i - k;
                int mirrorLeft = i - k - center[i - k];
                
                if (mirrorLeft == i - jold) {
                    j = center[mirror];
                    break;
                }
                
                center[i + k] = min(jold - k, center[i - k]);
                
                left[i + k + center[i + k]] = max(left[i + k + center[i + k]], center[i + k]);
                right[i + k - center[i + k]] = max(right[i + k - center[i + k]], center[i + k]);
                
                k++;
            }
            
            i += k;
        }
        
        for (int i = 1; i < n; i++) {
            if (left[i] < left[i - 1]) {
                left[i] = left[i - 1];
            }
            
            if (right[n - i - 1] < right[n - i]) {
                right[n - i - 1] = right[n - i];
            }
        }
        long long result = 1;
        for (int i = 0; i < n - 1; i++) {
            result = max(result, ((long long)left[i] * 2 + 1) * (right[i + 1] * 2 + 1));
        }
        return result;
    }
};