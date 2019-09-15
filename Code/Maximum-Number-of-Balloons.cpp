class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.size() < 7) {
            return 0;
        }
        int bcount = 0, acount = 0, lcount = 0, ocount = 0, ncount = 0;
        for (auto c : text) {
            if (c == 'b') {
                bcount++;
            }
            if (c == 'a') {
                acount++;
            }
            if (c == 'l') {
                lcount++;
            }
            if (c == 'o') {
                ocount++;
            }
            if (c == 'n') {
                ncount++;
            }
        }
        int result = text.size() / 7;
        result = min(result, bcount);
        result = min(result, acount);
        result = min(result, lcount / 2);
        result = min(result, ocount / 2);
        result = min(result, ncount);
        
        return result;
    }
};