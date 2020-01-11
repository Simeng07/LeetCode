class Solution {
    unordered_set<string> result;
public:
    int distinctEchoSubstrings(string text) {
        int size = text.size();
        string s1, s2;
        for (int i = 0; i < size; i++) {
            s1 = "";
            s2 = "";
            for (int j = 0; j < (size - i) / 2; j++) {
                if (j == 0) {
                    s1 = text.substr(i, 1);
                } else {
                    s1 += text[i + j];
                }
                if (result.find(s1) != result.end()) {
                    continue;
                }
                s2 = text.substr(i + j + 1, j + 1);
                if (s1 == s2) {
                    result.insert(s1);
                }
                // cout << s1 << " " << s2 << endl;
            }
        }
        return result.size();
    }
};