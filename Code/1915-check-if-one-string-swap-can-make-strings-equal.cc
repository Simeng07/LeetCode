class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        char a = '1', b = '1';
        bool used = false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (used) {
                    return false;
                }
                if (a == '1') {
                    a = s1[i];
                    b = s2[i];
                } else {
                    if (a == s2[i] && b == s1[i]) {
                        used = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        if (!used && a != '1') {
            return false;
        }
        return true;
    }
};