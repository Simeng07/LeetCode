class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while (index < str.length() && str[index] == ' ') {
            index++;
        }
        bool neg = false;
        if (str[index] == '+') {
            index++;
        } else if (str[index] == '-') {
            index++;
            neg = true;
        }
        bool hasNum = false;
        int result = 0;
        if (index < str.length()) {
            if (!isdigit(str[index])) {
                return 0;
            }
        } else {
            return 0;
        }
        while (index < str.length() && isdigit(str[index])) {
            int digit = str[index] - '0';
            if (!neg && (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit >= INT_MAX % 10))) {
                return INT_MAX;
            }
            if (neg && (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit >= INT_MAX % 10 + 1))) {
                return INT_MIN;
            }
            result = result * 10 + digit;
            index++;
        }
        if (neg) {
            result *= -1;
        }
        return result;
    }
};