class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            int begin = i;
            int end = i;
            while (end + 1 < s.length() && s[end + 1] == s[begin]) {
                end++;
            }
            while ( begin > 0 && end < s.length() - 1 && s[begin - 1] == s[end + 1]) {
                begin--;
                end++;
            }
            if (end - begin + 1 > result.length()) {
                result = s.substr(begin, end - begin + 1);
            }
        }
        return result;
    }
};