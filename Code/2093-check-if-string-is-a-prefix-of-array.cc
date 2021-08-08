class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int length = s.size();
        string concate = "";
        for (int i = 0; i < words.size(); i++) {
            concate += words[i];
            if (concate.size() == length) {
                if (concate == s) {
                    return true;
                } else {
                    return false;
                }
            }
            if (concate.size() > length) {
                return false;
            }
        }
        return false;
    }
};