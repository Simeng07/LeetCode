class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto &kv : knowledge) {
            m[kv[0]] = kv[1];
        }
        string result = "";
        bool bracket = false;
        string tmp = "";
        for (auto c : s) {
            if (c == '(') {
                bracket = true;
            } else if (c == ')') {
                if (m.find(tmp) == m.end()) {
                    result += '?';
                } else {
                    result += m[tmp];
                }
                tmp = "";
                bracket = false;
            } else {
                if (bracket) {
                    tmp += c;
                } else {
                    result += c;
                }
            }
        }
        return result;
    }
};