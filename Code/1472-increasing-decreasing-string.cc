class Solution {
public:
    string sortString(string s) {
        int a[26] = {0};
        for (auto c : s) {
            a[c - 'a']++;
        }
        string result = "";
        while (true) {
            bool has = false;
            for (int i = 0; i < 26; i++) {
                if (a[i] > 0) {
                    has = true;
                    char c = 'a' + i;
                    result += c;
                    a[i]--;
                }
            }
            if (!has) {
                return result;
            }
            has = false;
            for (int i = 25; i >= 0; i--) {
                if (a[i] > 0) {
                    has = true;
                    char c = 'a' + i;
                    result += c;
                    a[i]--;
                }
            }
            if (!has) {
                return result;
            }
        }
        return result;
    }
};