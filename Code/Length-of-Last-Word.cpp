class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int last = s.length() - 1;
        while (s[last] == ' ') {
            last--;
            if (last < 0) {
                return 0;
            }
        }
        int first = last;
        while (s[first] != ' ') {
            first--;
            if (first < 0) {
                break;
            }
        }
        return last - first;
    }
};