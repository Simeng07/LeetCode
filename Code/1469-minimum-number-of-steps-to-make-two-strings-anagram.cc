class Solution {
public:
    int minSteps(string s, string t) {
        if (s == t) {
            return 0;
        }
        int a[26] = {0};
        int b[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) {
                result += (a[i] - b[i]);
            }
        }
        return result;
    }
};