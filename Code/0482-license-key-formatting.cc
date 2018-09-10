class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int count = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (count == K) {
                    count = 0;
                    result = '-' + result;
                }
                char c = toupper(S[i]);
                result = c + result;
                count++;
            }
        }
        return result;
    }
};