class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result = "";
        string tmp;
        while (getline(ss, tmp, ' ')) {
            if (tmp != "") {
                if (result == "") {
                    result = tmp;
                } else {
                    result = tmp + " " + result;
                }
            }
        }
        return result;
    }
};