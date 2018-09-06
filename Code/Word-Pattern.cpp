class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> v;
        stringstream ss(str);
        while (!ss.eof()) {
            string word;
            getline(ss, word, ' ');
            v.push_back(word);
        }
        if (v.size() != pattern.length()) {
            return false;
        }
        for (int i = 0; i < pattern.length(); i++) {
            if (m1.find(pattern[i]) == m1.end() && m2.find(v[i]) == m2.end()) {
                m1[pattern[i]] = v[i];
                m2[v[i]] = pattern[i];
            } else if (m1.find(pattern[i]) != m1.end() && m2.find(v[i]) != m2.end()){
                if (m1[pattern[i]] != v[i] || m2[v[i]] != pattern[i] ) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};