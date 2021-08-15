class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        string::size_type idx;
        for (auto &pattern : patterns) {
            idx = word.find(pattern);
            if (idx != string::npos) {
                result++;
            }
        }
        return result;
    }
};