class Solution {
    unordered_set<string> m;
    vector<string> result;
    bool process(string sentence, string s, unordered_set<string>& dic) {
        if (s == "") {
            result.push_back(sentence);
            return true;
        }
        if (m.find(s) != m.end())
            return false;
        bool flag = false;
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            if (dic.find(prefix) != dic.end()) {
                if (process(sentence + (sentence.length() == 0 ? "" :" ") + prefix, s.substr(i), dic)) {
                    flag = true;;
                }
            }
        }
        if (!flag) {
            m.insert(s);
        }
        return flag;
    }
    
public:
    vector<string> wordBreak(string sentence, vector<string>& dic) {
        unordered_set<string> s(dic.begin(), dic.end());
        process("", sentence, s);
        return result;
    }
};