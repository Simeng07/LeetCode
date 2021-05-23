class Solution {
public:
    bool checkZeroOnes(string s) {
        int longest0 = 0, longest1 = 0, current0 = 0, current1 = 0;
        char last = s[0];
        if (last == '0') {
            current0++;
        } else {
            current1++;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (last == '0') {
                    current0++;
                } else {
                    longest1 = max(longest1, current1);
                    current0 = 1;
                    current1 = 0;
                }
            } else {
                if (last == '0') {
                    longest0 = max(longest0, current0);
                    current0 = 0;
                    current1 = 1;
                } else {
                    current1++;
                }
            }
            last = s[i];
        }
        longest1 = max(longest1, current1);
        longest0 = max(longest0, current0);
        return (longest1 > longest0);
    }
};