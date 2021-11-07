class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long a[100001] = {0};
        a[0] = (isV(word[0]) ? 1 : 0);
        for (int i = 1; i < n; i++) {
            a[i] = (isV(word[i]) ? 1 : 0) + a[i - 1];
        }
        long long result = 0; // n*s-sum(2*n-(2k+2)ak)
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
        result = n * s;
        cout << result << endl;
        for (int i = 0; i < n; i++) {
            result -= ((2 * n - 2 * i - 2) * a[i]);
        }
        return result;
    }
    
    bool isV(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
};