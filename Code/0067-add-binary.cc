class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        if (la < lb) {
            return addBinary(b, a);
        }
        int carry = 0;
        string result = "";
        for (int i = 1; i <= lb; i++) {
            int sum = addChar(a[la - i], b[lb - i], carry);
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        for (int i = lb + 1; i <= la; i++) {
            int sum = addChar(a[la - i], '0', carry);
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        if (carry > 0) {
            result = to_string(carry) + result;
        }
        return result;
    }
    
    int addChar(char a, char b, int carry) {
        int result = a - '0' + b - '0' + carry;
        switch (result) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 10;
            case 3:
                return 11;
            default: 
                return 0;
        }
    }
};