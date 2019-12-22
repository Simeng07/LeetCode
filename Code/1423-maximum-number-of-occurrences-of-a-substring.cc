class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int size = s.size();
        int c[26] = {0};
        unordered_set<char> st;
        for (int i = minSize; i <= maxSize; i++) {
            memset(c, 0, sizeof(c));
            st.clear();
            for (int j = 0; j < i; j++) {
                st.insert(s[j]);
                c[s[j] - 'a']++;
            }
            string tmp = s.substr(0, i);
            if (st.size() <= maxLetters) {
                m[tmp]++;
            }
            for (int j = 1; j <= size - i; j++) {
                c[s[j + i - 1] - 'a']++;
                st.insert(s[j + i - 1]);
                c[s[j - 1] - 'a']--;
                if (c[s[j - 1] - 'a'] == 0) {
                    st.erase(s[j - 1]);
                }
                tmp = tmp.substr(1, i - 1);
                tmp += s[j + i - 1];
                if (st.size() <= maxLetters) {
                    m[tmp]++;
                }
            }
        }
        int result = 0;
        for (auto it : m) {
            result = max(result, it.second);
        }
        return result;
    }
};