class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int count = s.length();
        if (count == 0) {
            return true;
        }
        unordered_map<char, char> m;
        unordered_map<char, char> r;
        for (int i = 0; i < count; i++) {
            if (m.find(s[i]) == m.end()) {
                if (r.find(t[i]) == r.end()) {
                    m[s[i]] = t[i];
                    r[t[i]] = s[i];
                } else {
                    return false;
                }
            } else {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};