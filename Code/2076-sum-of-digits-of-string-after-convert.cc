class Solution {
public:
    int getLucky(string s, int k) {
        string convert = "";
        for (auto c : s) {
            convert += to_string(c - 'a' + 1);
        }
        int result;
        while (k > 0) {
            result = 0;
            for (auto c : convert) {
                result += (c - '0');
            }
            convert = to_string(result);
            k--;
        }
        return result;
    }
};