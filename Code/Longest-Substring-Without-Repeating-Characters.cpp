class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n < 2) {
            return n;
        }
        int result = 1;
        int begin = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            if (m.find(s[i]) != m.end() && m[s[i]] >= begin) {
                result = max(result, i - begin);
                begin = m[s[i]] + 1;
            }
            m[s[i]] = i;
        }
        result = max(result, n - begin);
        return result;
    }
};