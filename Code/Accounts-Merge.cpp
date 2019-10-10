class Solution {
    vector<vector<string>> result;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        sort(accounts.begin(), accounts.end());
        string name = "";
        int startIndex = 0;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].size() == 0) {
                continue;
            }
            if (accounts[i][0] != name) {
                helper(accounts, name, startIndex, i - 1);
                name = accounts[i][0];
                startIndex = i;
            }
        }
        helper(accounts, name, startIndex, (int)accounts.size() - 1);
        return result;
    }
   
    void helper(vector<vector<string>>& accounts, string name, int start, int end) {
        if (start > end) {
            return;
        }
        set<int> s;
        for (int i = start; i <= end; i++) {
            s.insert(i);
        }
        for (int i = start; i <= end; i++) {
            if (s.find(i) == s.end()) {
                continue;
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                auto it = s.upper_bound(i);
                if (it == s.end()) {
                    break;
                }
                while (it != s.end()) {
                    if (*it > i && find(accounts[*it].begin(), accounts[*it].end(), accounts[i][j]) != accounts[*it].end()) {
                        accounts[i].insert(accounts[i].end(), accounts[*it].begin() + 1, accounts[*it].end());
                        s.erase(*it);
                    }
                    ++it;
                }
            }
            set<string> singlePerson(accounts[i].begin() + 1, accounts[i].end());
            vector<string> person = {name};
            person.insert(person.end(), singlePerson.begin(), singlePerson.end());
            result.push_back(person);
        }
    }
};