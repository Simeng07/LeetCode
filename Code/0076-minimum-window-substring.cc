class Solution {
public:
    // two pointers
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        unordered_map<char, int> current;
        unordered_set<char> need;
        for (auto c : t) {
            m[c]++;
            need.insert(c);
        }
        int begin = 0, end = 0;
        int resultBegin = -1, resultEnd = -1;
        string result = "";
        for (end; end < s.size(); end++) {
            if (m.find(s[end]) != m.end()) {
                current[s[end]]++;
                if (current[s[end]] >= m[s[end]]) {
                    need.erase(s[end]);
                }
                if (need.empty()) {
                    for (int i = begin; i < end; i++) {
                        if (m.find(s[i]) != m.end()) {
                            if (current[s[i]] > m[s[i]]) {
                                current[s[i]]--;
                            } else {
                                begin = i;
                                break;
                            }
                        } else {
                            begin = i + 1;
                        }
                    }
                    if (resultBegin == -1 || resultEnd - resultBegin > end - begin) {
                        resultBegin = begin;
                        resultEnd = end;
                    }
                }
            }
        }
        if (resultBegin == -1) {
            return "";
        }
        return s.substr(resultBegin, resultEnd - resultBegin + 1);;
    }
};