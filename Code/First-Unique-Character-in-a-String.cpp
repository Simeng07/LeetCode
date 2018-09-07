class Solution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (a[s[i] - 'a'] < 0) {
                continue;
            } else if (a[s[i] - 'a'] == 0) {
                a[s[i] - 'a']++;
            } else {
                a[s[i] - 'a'] = -1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (a[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};