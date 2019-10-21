class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()==0) return true;
        int p = 0;
        int q = s.length()-1;
        while (p<q) {
            // isalnum
            while (p<q && !isalnum(s[p])) p++;
            while (p<q && !isalnum(s[q])) q--;
            // toupper
            if (p<q && toupper(s[p])!=toupper(s[q])) return false;
            p++;
            q--;
        }
        return true;
    }
};