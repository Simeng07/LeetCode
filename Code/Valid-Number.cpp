class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        bool hasE = false;
        bool hasDot = false;
        while (s[i] == ' ' && i < s.length()) i++;
        if (i == s.length()) return false;
        if (s[i] == 'e') return false;
        if (s[i] == '-' || s[i] == '+') {
            if (i == s.length() - 1 || (!isdigit(s[i + 1]) && s[i + 1] != '.')) return false;
            i++;
        }
        if (s[i] == '.') {
            if (i == s.length() - 1 || !isdigit(s[i + 1])) return false;
            i++;
            hasDot = true;
        }
        for (; i < s.length(); i++) {
            if (isalpha(s[i])) {
                if (s[i] != 'e' || hasE || i == s.length() - 1 || (!isdigit(s[i + 1]) && s[i + 1] != '-' && s[i + 1] != '+')) return false;
                if (s[i + 1] == '-' || s[i + 1] == '+') {
                    if (i + 1 == s.length() - 1 || (!isdigit(s[i + 2]) && s[i + 2] != '.')) return false;
                    i++;
                }
                hasE = true;
            } else if (s[i] == '.') {
                if (hasDot || hasE) return false;
                hasDot = true;
            } else if (s[i] == ' ') {
                while (i < s.length() - 1)
                    if (s[++i] != ' ') return false;
                return true;
            } else if (!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }
};