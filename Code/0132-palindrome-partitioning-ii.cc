class Solution {
public:
    int minCut(string s) {
        int size = s.length();
        if (size < 2) {
            return 0;
        }
        
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = i;
        }
        
        for (int i = 0; i < size; i++) {
            helper(s, result, i, i);
            helper(s, result, i, i + 1);
        }
        
        return result[size - 1];
    }
    
    void helper(string &s, vector<int> &result, int begin, int end) {
        while (begin >= 0 && end <= s.length() && s[begin] == s[end]) {
            if (begin == 0) {
                result[end] = 0;
                return;
            } else {
                result[end] = min(result[end], result[begin - 1] + 1);
            }
            begin--;
            end++;
        }
    }
};