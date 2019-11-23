class Solution {
public:
    string toLowerCase(string str) {
        stringstream ss;
        for (int i = 0; i < str.length(); i++) {
            char a;
            if ('A' <= str[i] && str[i] <= 'Z') {
                a = str[i] + 'a' - 'A';
            } else {
                a = str[i];
            }
            ss << a;
        }
        return ss.str();
    }
};