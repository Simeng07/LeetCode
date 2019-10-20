class Solution {
public:
    int numDecodings(string s) {
        if (s.length() <= 0) return 0;
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        int a = 1;
        int b = 1;
        int result;
        // DP
        for (int i = 2; i <= s.length(); i++)
        {
            int tmp = s2i(s, i-1);
            if (tmp % 10 == 0 && tmp != 10 && tmp != 20) return 0;
            if (s[i-1] == '0') {
                result = a;
            } else if (tmp < 10 || tmp > 26) {
                result = b;
            } else {
                result = a + b;
            }
            a = b;
            b = result;
        }
        return result;
    }
    
    int s2i(string s, int a)
    {
        return ((s[a-1]-'0')*10+(s[a]-'0'));
    }
};