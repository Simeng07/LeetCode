class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int maskAll = (1 << n);
        int plength[1 << 12];
        
        for (int i = 1; i < maskAll; i++) {
            string seq = "";
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    seq = s[j] + seq;
                }
            }
            string rseq = seq;
            reverse(rseq.begin(), rseq.end());
            if (seq == rseq) {
                plength[i] = seq.length();
            } else {
                plength[i] = 1;
            }
        }
        
        int result = 1;
        
        for (int i = 0; i < maskAll; i++) {
            for (int j = i + 1; j < maskAll; j++) {
                if (!(i & j)) {
                    result = max(result, plength[i] * plength[j]);
                }
            }
        }
        
        return result;
    }
};