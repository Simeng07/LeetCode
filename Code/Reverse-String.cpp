class Solution {
public:
    void reverseString(vector<char>& s) {
        // int p = 0, q = s.length() - 1;
        // char tmp;
        // while (p < q) {
        //     if (s[p] != s[q]) {
        //         tmp = s[p];
        //         s[p] = s[q];
        //         s[q] = tmp;
        //     }
        //     p++;
        //     q--;
        // }
        // return s;
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};