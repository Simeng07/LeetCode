class Solution {
public:
    string reverseVowels(string s) {
        int p = 0;
        int q = s.length() - 1;
        char tmp;
        while (p < q) {
            while (p < q && !isVowel(s[p])) {
                p++;
            }
            while (p < q && !isVowel(s[q])) {
                q--;
            }
            if (p >= q) {
                return s;
            }
            // if (s[p] != s[q]) {
            //     tmp = s[p];
            //     s[p] = s[q];
            //     s[q] = tmp;
            // }
            swap(s[p], s[q]);
            p++;
            q--;
        }
        return s;
    }
    
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u') {
            return true;
        }
        if (c == 'A' || c == 'E' || c == 'I' || c =='O' || c == 'U') {
            return true;
        }
        return false;
    }
};