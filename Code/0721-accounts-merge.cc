class Solution {
    unordered_map<string, string> relates;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> leaders;
        for (auto &account : accounts) {
            if (account.size() <= 1) {
                continue;
            }
            string currentName = account[0];
            string currentLeader = account[1];
            
            if (relates.find(currentLeader) != relates.end()) {
                // has
                currentLeader = findLeader(currentLeader);
            } else {
                leaders[currentLeader] = currentName;
                relates[currentLeader] = currentLeader;
            }
            
            for (int i = 2; i < account.size(); i++) {
                if (account[i] == currentLeader) {
                    continue;
                }
                if (relates.find(account[i]) != relates.end()) {
                    string formerLeader = findLeader(account[i]);
                    if (findLeader(currentLeader) != formerLeader) {
                        // modify former leader
                        relates[formerLeader] = currentLeader;
                        leaders.erase(formerLeader);
                    }
                }
                relates[account[i]] = currentLeader;
            }
        }
        
        unordered_map<string, set<string>> m;
        for (auto &account : relates) {
            // group those accounts
            m[findLeader(account.second)].insert(account.first);
        }
        
        vector<vector<string>> result;
        for (auto &group : m) {
            vector<string> v(1 + (group.second).size());
            // name
            int index = 0;
            v[index] = leaders[group.first];
            // accounts
            index++;
            for (auto &mail : group.second) {
                v[index++] = mail;
            }
            result.push_back(v);
        }
        
        return result;
    }
    
    string findLeader(string account) {
        while (account != relates[account]) {
            account = relates[account];
        }
        return account;
    }
};