class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x = 0, y = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                x++;
            }
            if (s1[i] == 'y' && s2[i] == 'x') {
                y++;
            }
        }
        if ((x + y) % 2 == 1) {
            return -1;
        }
        int result = 0;
        result += x / 2;
        result += y / 2;
        result += x % 2;
        result += y % 2;
        return result;
    }
};