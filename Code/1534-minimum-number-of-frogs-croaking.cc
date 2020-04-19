class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) {
            return -1;
        }
        
        int result = 0;
        int current = 0;
        
        int progress[4] = {0};
        
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            char c = croakOfFrogs[i];
            if (c == 'c') {
                current++;
                result = max(result, current);
                progress[0]++;
            } else if (c == 'k') {
                if (progress[3] == 0) {
                    return -1;
                } else {
                    progress[3]--;
                    current--;
                }
            } else {
                int lastP = cti(c) - 1;
                if (progress[lastP] == 0) {
                    return -1;
                } else {
                    progress[lastP]--;
                    progress[lastP + 1]++;
                }
            }
        }
        
        return result;
    }
    
    int cti(char c) {
        if (c == 'c') {
            return 0;
        }
        if (c == 'r') {
            return 1;
        }
        if (c == 'o') {
            return 2;
        }
        if (c == 'a') {
            return 3;
        }
        if (c == 'k') {
            return 4;
        }
        return -1;
    }
};