class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        unordered_map<int, int> last, next, left;
        int pre = -1;
        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            last[i] = pre;
            if (s[i] == '|') {
                pre = i;
                current++;
            }
            left[i] = current;
        }
        pre = -1;
        current = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            next[i] = pre;
            if (s[i] == '|') {
                pre = i;
                current ++;
            }
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int begin = s[queries[i][0]] == '|' ? queries[i][0] : next[queries[i][0]];
            int end = s[queries[i][1]] == '|' ? queries[i][1] : last[queries[i][1]];
            if (begin >= end || begin == -1 || end == -1) {
                continue;
            }
            result[i] = end - begin - 1 - (left[end - 1] - left[begin]);
            
        }
        return result;
    }
};