class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        int size = s.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (first[s[i] - 'a'] < 0) {
                count++;
                first[s[i] - 'a'] = i;
                if (count == 26) {
                    break;
                }
            }
        }
        count = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (last[s[i] - 'a'] < 0) {
                count++;
                last[s[i] - 'a'] = i;
                if (count == 26) {
                    break;
                }
            }
        }
        
        vector<string> all;
        for (int i = 0; i < size; i++) {
            if (first[s[i] - 'a'] == i) {
                int end = last[s[i] - 'a'];
                bool valid = true;
                for (int j = i + 1; j < end; j++) {
                    if (first[s[j] - 'a'] < i) {
                        valid = false;
                        break;
                    }
                    end = max(end, last[s[j] - 'a']);
                }
                if (valid) {
                    all.push_back(s.substr(i, end - i + 1));
                }
            }
        }
        
        sort(all.begin(), all.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });
        
        vector<string> result;
        
        bool has[26] = {0};
        count = 0;
        for (auto &str : all) {
            bool valid = true;
            for (auto &c : str) {
                if (has[c - 'a']) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (auto &c : str) {
                    has[c - 'a'] = true;
                }
                result.push_back(str);
                count += str.size();
                if (count == 26) {
                    return result;
                }
            }
        }
        
        return result;
    }
};


// a better one
//
// pay attention to: res.back() = s.substr(i, right - i + 1);
//
// class Solution {
// public:
//     vector<string> maxNumOfSubstrings(string s) {
//         vector<int> front(26, -1);
//         vector<int> back(26, -1);
//         for(int i = 0; i < s.size(); i++) {
//             if(front[s[i] - 'a'] == -1) front[s[i] - 'a'] = i;
//         }
//         for(int i = s.size() - 1; i >= 0; i--) {
//             if(back[s[i] - 'a'] == -1) back[s[i] - 'a'] = i;
//         }
//         vector<string> res;
//         int right = INT_MAX;
//         for(int i = 0; i < s.size(); i++) {
//             if(front[s[i] - 'a'] == i) {
//                 int new_right = getRight(s, i, front, back);
//                 if(new_right != -1) {
//                     if(i > right || res.empty()) {
//                         res.push_back("");
//                     }
//                     right = new_right;
//                     res.back() = s.substr(i, right - i + 1);
//                 }
//             }
//         }
            
//         return res;
//     }
//     int getRight(string& s, int cur, vector<int>& l, vector<int>& r) {
//         int right = r[s[cur] - 'a'];
//         for(int i = cur; i <= right; i++) {
//             if(l[s[i] - 'a'] < cur) return -1;
//             right = max(right, r[s[i] - 'a']);
//         }
//         return right;
//     }
// };