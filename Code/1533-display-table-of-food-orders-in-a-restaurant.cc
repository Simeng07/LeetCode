class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string> dishes;
        map<int, unordered_map<string, int>> od;
        for (auto &order : orders) {
            od[stoi(order[1])][order[2]]++;
            dishes.insert(order[2]);
        }
        
        vector<string> header(dishes.begin(), dishes.end());
        sort(header.begin(), header.end());
        header.insert(header.begin(), "Table");
        
        vector<vector<string>> result;
        result.push_back(header);
        
        for (auto it = od.begin(); it != od.end(); ++it) {
            vector<string> tableOd(dishes.size() + 1, "0");
            tableOd[0] = to_string(it->first);
            for (int i = 1; i < header.size(); i++) {
                if (it->second[header[i]] != 0) {
                    tableOd[i] = to_string(it->second[header[i]]);
                }
            }
            result.push_back(tableOd);
        }
        
        return result;
    }
};