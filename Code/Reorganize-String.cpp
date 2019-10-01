class Solution {
public:
    string reorganizeString(string S) {
        int size = S.length();
        
        int cs[26] = {0};
        for (auto c : S) {
            cs[c - 'a']++;
        }
        
        map<int, string, greater<int>> m;
        for (int i = 0; i < 26; i++) {
            if (cs[i] != 0) {
                m[cs[i]].push_back('a' + i);
            }
        }
        
        if (m.begin()->first > (size + 1) / 2) {
            return "";
        }
        
        stringstream ss;
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                for (int i = 0; i < it->first; i++) {
                    ss << *it2;
                }
            }
        }
        
        string tmp;
        ss >> tmp;
        
        stringstream resultss;
        for (int i = 0; i < (size + 1) / 2; i++) {
            resultss << tmp[i];
            if (i + (size + 1) / 2 < size) {
                resultss << tmp[i + (size + 1) / 2];
            }
        }
        
        string result;
        resultss >> result;
        return result;
    }
};