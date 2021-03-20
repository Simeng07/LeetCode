class Solution {
public:
    int secondHighest(string s) {
        bool a[10] = {0};
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                a[c - '0'] = true;
            }
        }
        bool flag = false;
        for (int i = 9; i >= 0; i--) {
            if (a[i]) {
                if (!flag) {
                    flag = true;
                } else {
                    return i;
                }
            }
        }
        return -1;
    }
};