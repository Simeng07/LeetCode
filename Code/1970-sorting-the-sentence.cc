class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(10);
        for (int i = 0; i < 10; i++) {
            v[i] = "";
        }
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] > '0' && s[i] <= '9') {
                int index = s[i] - '0';
                v[index] = tmp;
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        string result = "" + v[1];
        for (int i = 2; i < 10; i++) {
            if (v[i] == "") {
                return result;
            }
            result += " ";
            result += v[i];
        }
        return result;
    }
};