class Solution {
    unordered_map<string, unordered_map<string, double>> m;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = values.size();
        for (int i = 0; i < size; i++) {
            m[equations[i][0]][equations[i][1]] = values[i];
            if (values[i] != 0) {
                m[equations[i][1]][equations[i][0]] = 1 / values[i];
            }
        }
        vector<double> result;
        for (auto &query : queries) {
            string a = query[0];
            string b = query[1];
            if (m.find(a) == m.end() || m.find(b) == m.end()) {
                result.push_back(-1.0);
                continue;
            }
            if (m.find(a) != m.end() && m[a].find(b) != m[a].end()) {
                result.push_back(m[a][b]);
                continue;
            }
            unordered_set<string> has;
            result.push_back(mfind(a, b, 1, has));
        }
        return result;
    }
    double mfind(string a, string b, double current, unordered_set<string> has) {
        if (has.find(a) != has.end()) {
            return -1;
        }
        has.insert(a);
        double result = -1;
        for (auto &mm : m[a]) {
            if (mm.first == b) {
                return current * mm.second;
            }
            result = mfind(mm.first, b, mm.second * current, has);
            if (result != -1) {
                return result;
            }
        }
        return result;
    }
};