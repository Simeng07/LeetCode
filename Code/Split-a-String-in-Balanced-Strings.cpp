class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.length() < 2) {
            return 0;
        }
        int countl = 0, countr = 0, result = 0;
        for (auto c : s) {
            if (c == 'L') {
                countl++;
            }
            if (c == 'R') {
                countr++;
            }
            if (countl == countr) {
                result++;
                countr = 0;
                countl = 0;
            }
        }
        return result;
    }
};