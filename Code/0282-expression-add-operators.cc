class Solution {
    vector<string> result;
public:
    vector<string> addOperators(string num, int target) {
        helper(num, target, 0, "", 0, 0);
        return result;
    }
    
    void helper(string &num, int target, int index, string prevString, long prevNum, long lastCal) {
        if (index == num.size()) {
            if (target == prevNum) {
                result.push_back(prevString);
            }
            return;
        }
        for (int length = 1; index + length - 1 < num.size(); length++) {
            string s = num.substr(index, length);
            if (length != 1 && s[0] == '0') {
                break;
            }
            long l = stol(s);
            if (index == 0) {
                helper(num, target, length, s, l, l);
            } else {
                helper(num, target, index + length, prevString + "+" + s, prevNum + l, l);
                helper(num, target, index + length, prevString + "-" + s, prevNum - l, -l);
                // reverse the last operation if the next one is *
                helper(num, target, index + length, prevString + "*" + s, prevNum - lastCal + lastCal * l, lastCal * l);
            }
        }
    }
};
// class Solution {
// public:
//     vector<string> addOperators(string num, int target) {
//         unordered_map<string, unordered_map<int, unordered_set<string>>> m;
//         for (int length = 1; length <= num.size(); length++) {
//             for (int index = 0; index + length - 1 < num.size(); index++) {
//                 string s0 = num.substr(index, length);
//                 if (m.find(s0) != m.end()) {
//                     continue;
//                 }
//                 if (!(s0.size() > 1 && s0[0] == '0')) {
//                     m[s0][stoi(s0)].insert(s0);
//                 }
//                 for (int left = 1; left < length; left++) {
//                     string s1 = num.substr(index, left);
//                     string s2 = num.substr(index + left, length - left);
//                     if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) {
//                         continue;
//                     }
//                     for (auto it1 = m[s1].begin(); it1 != m[s1].end(); ++it1) {
//                         for (auto it2 = m[s2].begin(); it2 != m[s2].end(); ++it2) {
//                             for (auto it3 = (it1->second).begin(); it3 != (it1->second).end(); ++it3) {
//                                 for (auto it4 = (it2->second).begin(); it4 != (it2->second).end(); ++it4) {
//                                     m[s0][it1->first + it2->first].insert(*it3 + "+" + *it4);
//                                     m[s0][it1->first - it2->first].insert(*it3 + "-" + *it4);
//                                     if ((*it3).find('+') == string::npos && (*it3).find('-') == string::npos && (*it4).find('+') == string::npos && (*it4).find('-') == string::npos) {
//                                         m[s0][it1->first * it2->first].insert(*it3 + "*" + *it4);
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         vector<string> result(m[num][target].begin(), m[num][target].end());
//         return result;
//     }
// };