class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        // The given RPN expression is always valid.
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int i1 = stk.top();
                stk.pop();
                int i2 = stk.top();
                stk.pop();
                if (token == "+") {
                    stk.push(i2 + i1);
                } else if (token == "-") {
                    stk.push(i2 - i1);
                } else if (token == "*") {
                    stk.push(i2 * i1);
                } else {
                    stk.push(i2 / i1);
                }
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};