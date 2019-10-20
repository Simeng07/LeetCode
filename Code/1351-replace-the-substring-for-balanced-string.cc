class Solution {
public:
    int balancedString(string s) {
        int count[4] = {0};
        int average = s.length() / 4;
        for (auto c : s) {
            count[convert(c)]++;
        }
        int exceedQ = count[0] - average;
        int exceedW = count[1] - average;
        int exceedE = count[2] - average;
        int exceedR = count[3] - average;
        if (exceedQ == 0 && exceedW == 0 && exceedE == 0 && exceedR == 0) {
            return 0;
        }
        if (exceedQ == 3 * average || exceedW == 3 * average || exceedE == 3 * average || exceedR == 3 * average) {
            return s.length() / 4 * 3;
        }
        // cout << exceedQ << " " << exceedW << " " <<  exceedE << " " << exceedR << endl;
        int subCount[4] = {0};
        int result = s.length();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                subCount[convert(s[j])]++;
                if (subCount[0] >= exceedQ && subCount[1] >= exceedW && subCount[2] >= exceedE && subCount[3] >= exceedR) {
                    result = min(result, j - i + 1);
                    break;
                }
            }
            subCount[0] = subCount[1] = subCount[2] = subCount[3] = 0;
        }
        return result;
    }
    
    int convert(char c) {
        if (c == 'Q') {
            return 0;
        }
        if (c == 'W') {
            return 1;
        }
        if (c == 'E') {
            return 2;
        }
        if (c == 'R') {
            return 3;
        }
        return 0;
    }
};