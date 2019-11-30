class Solution {
public:
    string toHexspeak(string num) {
        long long llnum = stoll(num);
        string result = "";
        while (true) {
            int n = llnum % 16;
            if (n == 0) {
                result = 'O' + result;
            } else if (n == 1) {
                result = 'I' + result;
            } else if (n > 9) {
                char c = 'A' + n - 10;
                result = c + result;
            } else {
                return "ERROR";
            }
            llnum /= 16;
            if (llnum == 0) {
                return result;
            }
        }
        return result;
    }
};