class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        bool hasA = false;
        bool hasB = false;
        for (int i = 0; i < s.size(); i++) {
            if (hasA && hasB) {
                break;
            }
            if (s[i] == 'a') {
                hasA = true;
            }
            if (s[i] == 'b') {
                hasB = true;
            }
        }
        if (!hasA || !hasB) {
            return 1;
        }
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return 2;
            }
        }
        return 1;
    }
};