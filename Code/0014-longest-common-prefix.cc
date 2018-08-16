class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int count = 0;
        int min = strs[0].length();
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < min) {
                min = strs[i].length();
            }
        }
        for (count = 0; count < min; count++) {
            char c = strs[0][count];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][count] != c) {
                    return strs[0].substr(0, count);
                }
            }
        }
        return strs[0].substr(0, count);
    }
};