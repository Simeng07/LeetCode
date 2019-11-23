class Solution {
public:
    int longestPalindrome(string s) {
        int a[52] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] > 'Z') {
                a[s[i] - 'a' + 26]++;
            } else {
                a[s[i] - 'A']++;
            }
        }
        bool hasOdd = false;
        int result = 0;
        for (int i = 0; i < 52; i++) {
            result += a[i] / 2 * 2;
            if (!hasOdd && a[i] % 2 != 0) {
                result += 1;
                hasOdd = true;
            }
        }
        return result;
        
        // if (s.size() == 0) return 0;
        // sort(s.begin(), s.end());
        // int result = 0;
        // bool pairing = true; // 求配对
        // for (int i = 1; i < s.size(); i++) {
        //     if ((s[i] == s[i - 1]) && pairing) {
        //         pairing = false;
        //         result += 2;
        //     } else {
        //         pairing = true;
        //     }
        // }
        // if (result != s.size()) result++;
        // return result;
    }
};