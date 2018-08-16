class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        stack<char> stack;
        unordered_map<char, char> map = { {')', '('}, {']', '['}, {'}', '{'} };
        for (int i = 0; i < s.length(); i++) {
            if (stack.empty() || stack.top() != map[s[i]]) {
                stack.push(s[i]);
            } else {
                stack.pop();
            }
        }
        return stack.empty();
    }
};