class Solution {
    string dic[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        string str = "";
        helper(digits, 0, str);
        return result;
    }
    
    void helper(string &digits, int i, string str) {
        if (i >= digits.length()) {
            result.push_back(str);
            return;
        }
        string letters = dic[digits[i] - '0'];
        for (int j = 0; j < letters.length(); j++) {
            // 这种 string + char 也可以哦!!!
            helper(digits, i + 1, str + letters[j]);
        }
    }
};