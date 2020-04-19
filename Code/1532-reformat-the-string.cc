class Solution {
public:
    string reformat(string s) {
        string letters = "";
        string digits = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                letters += c;
            } else {
                digits += c;
            }
        }
        int lsize = (int)letters.size();
        int dsize = (int)digits.size();
        if (abs(lsize - dsize) > 1) {
            return "";
        }
        string result = "";
        for (int i = 0; i < min(lsize, dsize); i++) {
            result += letters[i];
            result += digits[i];
        }
        if (lsize < dsize) {
            result = digits[dsize - 1] + result;
        }
        if (lsize > dsize) {
            result += letters[lsize - 1];
        }
        return result;
    }
};