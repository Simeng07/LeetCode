class Solution {
public:
    bool canConstruct(string s, int k) {
        int size = s.size();
        if (size < k) {
            return false;
        }
        if (size == k) {
            return true;
        }
        int count[26] = {0};
        for (int i = 0; i < size; i++) {
            count[s[i] - 'a']++;
        }
        int odd = 0, even = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                if (count[i] % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }
        if (odd > k) {
            return false;
        } else {
            return true;
        }
    }
};