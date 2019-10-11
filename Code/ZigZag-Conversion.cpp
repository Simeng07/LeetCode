class Solution {
public:
    string convert(string s, int nRows) {
        if (s.length() <= nRows || nRows <= 1) return s;
        string result = "";
        for (int i = 0; i < nRows; i++) {
            result += s[i];
            int index = i + 2 * nRows - 2;
            while (index - 2 * i < s.length()) {
                if (i != 0 && i != nRows - 1) 
                    result += s[index - 2 * i];
                if (index < s.length())
                    result += s[index];
                index += 2 * nRows - 2;
            }
        }
        return result;
    }
};