class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count1[26] = {0};
        int count2[26] = {0};
        for (int i = 0; i < word1.size(); i++) {
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            if (abs(count1[i] - count2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};