class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> result(s.length() + 1, false);
        helper(0, result, s, wordDict);
        return result.back();
    }
    void helper(int begin, vector<bool> &result, string &s, vector<string>& wordDict) {
        if (result.back()) {
            return;
        }
        if (begin == s.length()) {
            result[begin] = true;
            return;
        }
        for (auto word : wordDict) {
            if (result.back()) {
                return;
            }
            int index = min(begin + word.length(), s.length());
            if (result[index]) {
                continue;
            }
            string tmp = s.substr(begin, word.length());
            if (tmp == word) {
                result[index] = true;
                helper(index, result, s, wordDict);
            }
        }
    }
};