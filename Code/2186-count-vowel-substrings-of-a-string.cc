class Solution {
public:
    int countVowelSubstrings(string word) {
        int result = 0;
        for (int i = 0; i <= word.size(); i++) {
            if (isV(word[i])) {
                int j = 5;
                while (i + j <= word.size()) {
                    int isGood = isVS(word.substr(i, j));
                    if (isGood == -1) {
                        break;
                    } else if (isGood == 1) {
                        result++;
                    }
                    j++;
                }
            }
        }
        return result;
    }
    bool isV(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    int isVS(string s) {
        bool hasa = false, hase = false, hasi = false, haso = false, hasu = false;
        for (auto &c : s) {
            if (isV(c)) {
                if (c == 'a') hasa = true;
                if (c == 'e') hase = true;
                if (c == 'i') hasi = true;
                if (c == 'o') haso = true;
                if (c == 'u') hasu = true;
            } else {
                return -1;
            }
        }
        return (hasa && hase && hasi && haso && hasu) ? 1 : 0;
    }
};