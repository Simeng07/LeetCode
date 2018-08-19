class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        string result = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            int j = 0;
            while (j < result.length()) {
                int current = j;
                while (result[current] == result[j] && current < result.length()) {
                    current++;
                }
                tmp = tmp + to_string(current - j) + result[j];
                j = current;
                
            }
            result = tmp;
        }
        return result;
    }
};