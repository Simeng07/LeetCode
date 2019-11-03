class Solution {
public:
    string minRemoveToMakeValid(string s) {
        bool valid[100001] = {false};
        stack<int> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                valid[i] = true;
            }
            if (s[i] == ')') {
                if (stk.empty()) {
                    valid[i] = false;
                } else {
                    valid[stk.top()] = true;
                    valid[i] = true;
                    stk.pop();
                }
            }
            if (s[i] == '(') {
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            valid[stk.top()] = false;
            stk.pop();
        }
        stringstream ss;
        for (int i = 0; i < s.length(); i++) {
            if (valid[i]) {
                ss << s[i];
            }
        }
        return ss.str();
    }
};