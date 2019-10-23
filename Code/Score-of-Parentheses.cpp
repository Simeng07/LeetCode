class Solution {
public:
    int scoreOfParentheses(string S) {
        int current = 0, result = 0;
        stack<int> stk;
        for (auto c : S) {
            if (c == '(') {
                stk.push(-1);
            }
            if (c == ')') {
                if (stk.empty()) {
                    continue;
                }
                int top = stk.top();
                stk.pop();
                if (top == -1) {
                    if (stk.empty() || stk.top() == -1) {
                        stk.push(1);
                    } else {
                        stk.top() += 1;
                    }
                } else {
                    int left = stk.top();
                    stk.pop();
                    if (left == -1) {
                        if (stk.empty() || stk.top() == -1) {
                            stk.push(2 * top);
                        } else {
                            stk.top() += 2 * top;
                        }
                    }
                }
            }
        }
        return ((stk.empty() || stk.top() == -1) ? 0 : stk.top());
    }
};