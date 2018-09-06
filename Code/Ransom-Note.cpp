class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        int a[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            a[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            a[ransomNote[i] - 'a']--;
            if (a[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};