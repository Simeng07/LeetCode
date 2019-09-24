class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() <= 10) {
            return result;
        }
        unordered_map<string, int> m;
        for (int i = 0; i <= s.length() - 10; i++) {
            string tmp = s.substr(i, 10);
            if (m.find(tmp) == m.end()) {
                m[tmp] = 1;
            } else {
                if (m[tmp] == 1) {
                    m[tmp]++;
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};