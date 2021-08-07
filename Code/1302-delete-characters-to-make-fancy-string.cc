class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        char last = '0';
        int lastCount = 0;
        for (auto c : s) {
            if (c == last) {
                lastCount++;
                if (lastCount < 3) {
                    result += c;
                }
            } else {
                last = c;
                result += c;
                lastCount = 1;
            }
        }
        return result;
    }
};