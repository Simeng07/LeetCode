class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        bool letter = true;
        string current = "";
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                letter = false;
                if (current == "" && word[i] == '0') {
                    continue;
                }
                current += word[i];
            } else {
                if (!letter) {
                    if (current == "") {
                        current = "0";
                    }
                    s.insert(current);
                    current = "";
                    letter = true;
                }
            }
        }
        if (!letter) {
            if (current == "") {
                current = "0";
            }
            s.insert(current);
            letter = true;
        }
        return s.size();
    }
};