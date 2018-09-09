class Solution {
public:
    int countSegments(string s) {
        bool inChunk = false;
        int index = 0;
        while ((s[index] == ' ' || s[index] == '\t') && index < s.length()) {
            index++;
        }
        if (index == s.length()) {
            return 0;
        }
        int result = 0;
        while (index < s.length()) {
            if (s[index] != ' ' && s[index] != '\t') {
                if (!inChunk) {
                    inChunk = true;
                    result++;
                }
            } else {
                inChunk = false;
            }
            index++;
        }
        return result;
    }
};