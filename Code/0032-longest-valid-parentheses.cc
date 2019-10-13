class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) return 0;
        stack<int> stk; // using stack to record the index
        stk.push(-1);
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int t = stk.top();
            if (t != -1 && s[i] == ')' && s[t] == '(') {
                stk.pop();
                result = max(result, i - stk.top()); // notice. not i - t, but i - stk.top()
            } else {
                stk.push(i);
            }
        }
        return result;
    }
};