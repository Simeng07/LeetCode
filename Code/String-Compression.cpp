class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) {
            return 0;
        }
        int j = 1;
        int c = chars[0];
        int n = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == c) {
                n++;
            } else {
                c = chars[i];
                if (n > 1) {
                    string count = to_string(n);
                    for (int k = 0; k < count.length(); k++) {
                        chars[j] = count[k];
                        j++;
                    }
                }
                n = 1;
                chars[j] = c;
                j++;
            }
        }
        if (n > 1) {
            string count = to_string(n);
            for (int k = 0; k < count.length(); k++) {
                chars[j] = count[k];
                j++;
            }
        }
        return j;
    }
};