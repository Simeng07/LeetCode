class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return result;
    }
    void helper(string current, int left, int right, int total) {
        if (left == total && right == total) {
            result.push_back(current);
            return;
        }
        if (left < total) {
            helper(current + "(", left + 1, right, total);
        }
        if (right < total && left > right) {
            helper(current + ")", left, right + 1, total);
        }
    }
};