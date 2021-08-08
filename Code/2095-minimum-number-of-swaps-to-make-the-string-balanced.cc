class Solution {
public:
    int minSwaps(string s) {
        int p = 0, q = s.size() - 1;
        int left = 0, right = 0;
        int resultp = 0, resultq = 0;
        while (p < q) {
            while (p < q && s[p] == '[') {
                left++;
                p++;
            }
            if (p < q) {
                if (left > 0) {
                    left--;
                } else {
                    left = 1;
                    resultp++;
                }
            }
            
            while (p < q && s[q] == ']') {
                right++;
                q--;
            } 
            if (p < q) {
                if (right > 0) {
                    right--;
                } else {
                    right = 1;
                    resultq++;
                }
            }
            
            p++;
            q--;
        }
        return max(resultp, resultq);
    }
};