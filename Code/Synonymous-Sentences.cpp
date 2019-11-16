class Solution {
    unordered_map<string, unordered_set<string>> m;
    vector<string> result;
    vector<string> v;
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto synonym: synonyms) {
            m[synonym[0]].insert(synonym[0]);
            m[synonym[1]].insert(synonym[1]);
            m[synonym[0]].insert(synonym[1]);
            m[synonym[1]].insert(synonym[0]);
            auto &us = m[synonym[0]];
            for (auto it = us.begin(); it != us.end(); ++it) {
                m[*it].insert(synonym[1]);
            }
            us = m[synonym[1]];
            for (auto it = us.begin(); it != us.end(); ++it) {
                m[*it].insert(synonym[0]);
            }
            // cout << synonym[0] << " " << synonym[1] << endl;
        }
        
        stringstream ss(text);
        string word;
        while (ss >> word) {
            v.push_back(word);
        }
        helper("", 0);
        sort(result.begin(), result.end());
        return result;
    }
    void helper(string current, int index) {
        // cout << current << " "<< index << endl;
        if (index >= v.size()) {
            result.push_back(current);
            return;
        }
        if (m.find(v[index]) == m.end()) {
            if (current == "") {
                current = v[index];
            } else {
                current = current + " " + v[index];
            }
            helper(current, index + 1);
            return;
        }
        auto &us = m[v[index]];
        for (auto it = us.begin(); it != us.end(); ++it) {
            string tmp = current;
            if (tmp == "") {
                tmp = *it;
            } else {
                tmp = tmp + " " + *it;
            }
            helper(tmp, index + 1);
        }
    }
};