class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), greater<int>());
        if (digits[0] == 0) {
            return "0";
        }
        int sum = 0;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < digits.size(); i++) {
            sum += digits[i];
            if (digits[i] % 3 == 1) {
                index1 = i;
            }
            if (digits[i] % 3 == 2) {
                index2 = i;
            }
        }
        if (sum % 3 == 0) {
            stringstream ss;
            for (auto i : digits) {
                ss << i;
            }
            return ss.str();
        }
        if (index1 == -1 && index2 == -1) {
            return "";
        }
        if (sum % 3 == 1) {
            if (index1 != -1) {
                stringstream ss;
                for (int i = 0; i < digits.size(); i++) {
                    if (i != index1) {
                        ss << digits[i];
                    }
                }
                return ss.str();
            } else {
                int i2 = -1;
                for (int i = digits.size() - 1; i >= 0; i--) {
                    if (digits[i] % 3 == 2 && i != index2) {
                        i2 = i;
                        break;
                    }
                }
                stringstream ss;
                for (int i = 0; i < digits.size(); i++) {
                    if (i != index2 && i != i2) {
                        ss << digits[i];
                    }
                }
                return ss.str();
            }
        }
        if (sum % 3 == 2) {
            if (index2 != -1) {
                stringstream ss;
                for (int i = 0; i < digits.size(); i++) {
                    if (i != index2) {
                        ss << digits[i];
                    }
                }
                return ss.str();
            } else {
                int i1 = -1;
                for (int i = digits.size() - 1; i >= 0; i--) {
                    if (digits[i] % 3 == 1 && i != index1) {
                        i1 = i;
                        break;
                    }
                }
                stringstream ss;
                for (int i = 0; i < digits.size(); i++) {
                    if (i != index1 && i != i1) {
                        ss << digits[i];
                    }
                }
                return ss.str();
            }
        }
        return "";
    }
};