class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m = s.length();
        if (m < 2) {
            return false;
        }
        int n = m / 2 + 1;
        for (int i = 1; i < n; i++) {
            if (m % i == 0) {
                bool find = true;
                string subs = s.substr(0, i);
                for (int j = 1; j * i + i <= m; j++) {
                    if (s.substr(i * j, i) != subs) {
                        find = false;
                        break;
                    }
                }
                if (find) {
                    return true;
                }
            }
        }
        return false;
    }
};