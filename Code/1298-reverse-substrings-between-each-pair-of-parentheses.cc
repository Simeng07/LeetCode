class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");
        for (auto c : s) {
            if (c == '(') {
                stk.push("");
            } else if (c == ')') {
                string sub = stk.top();
                stk.pop();
                reverse(sub.begin(), sub.end());
                stk.top() += sub;
            } else {
                stk.top().push_back(c);
            }
        }
        return stk.top();
    }
};