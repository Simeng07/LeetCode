class Solution {
public:
    int numberOfSubstrings(string s) {
        int size = s.size();
        int positions[3][size];
        int index[3] = {0};
        for (int i = 0; i < size; i++) {
            positions[0][i] = positions[1][i] = positions[2][i] = -1;
        }
        for (int i = 0; i < size; i++) {
            int charIndex = s[i] - 'a';
            positions[charIndex][index[charIndex]] = i;
            index[charIndex]++;
        }
        index[0] = index[1] = index[2] = 0;
        int result = 0;
        for (int i = 0; i < size - 2; i++) {
            // current char
            int charIndex = s[i] - 'a';
            if (positions[charIndex][index[charIndex]] < i) {
                index[charIndex]++;
            }
            int maxIndex = i;
            // the other two chars
            for (int j = 0; j < 2; j++) {
                charIndex = (charIndex + 1) % 3;
                if (positions[charIndex][index[charIndex]] <= i) {
                    index[charIndex]++;
                    if (positions[charIndex][index[charIndex]] == -1) {
                        return result;
                    }
                }
                maxIndex = max(maxIndex, positions[charIndex][index[charIndex]]);
            }
            result += (size - maxIndex);
        }
        return result;
    }
};