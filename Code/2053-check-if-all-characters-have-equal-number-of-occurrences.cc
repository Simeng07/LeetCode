class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int count[26] = {0};
        int has = -1;
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            if (has == -1) has = (s[i] - 'a');
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0 && count[i] != count[has]) {
                return false;
            }
        }
        return true;
    }
};