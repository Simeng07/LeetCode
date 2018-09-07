class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26] = {0};
        for (int i = 0; i < t.length(); i++) {
            a[t[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] == 1) {
                return (i + 'a');
            }
        }
        return 'a';
    }
};