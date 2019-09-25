class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};