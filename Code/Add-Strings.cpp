class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        if (l1 == 0) {
            return num2;
        }
        if (l2 == 0) {
            return num1;
        }
        if (l1 < l2) {
            return addStrings(num2, num1);
        }
        int carry = 0;
        string result = "";
        for (int i = 0; i < l2; i++) {
            int a = (num1[l1 - 1 - i] - '0') + (num2[l2 - 1 - i] - '0') + carry;
            int b = a % 10;
            carry = a / 10;
            char digit = b + '0';
            result = digit + result;
        }
        for (int i = l2; i < l1; i++) {
            int a = (num1[l1 - 1 - i] - '0') + carry;
            int b = a % 10;
            carry = a / 10;
            char digit = b + '0';
            result = digit + result;
        }
        if (carry != 0) {
            char digit = carry + '0';
            result = digit + result;
        }
        if (result == "") {
            return "0";
        }
        return result;
    }
};