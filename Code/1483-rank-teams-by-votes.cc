class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1) {
            return votes[0];
        }
        bool has[26] = {0};
        vector<vector<int>> count(26, vector<int>(27, 0));
        // count[i][0]: team letter
        for (int i = 0; i < 26; i++) {
            count[i][0] = i;
        }
        for (auto &vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                count[vote[i] - 'A'][i + 1]++;
                has[vote[i] - 'A'] = true;
            }
        }
        sort(count.begin(), count.end(), [](vector<int> a, vector<int> b){
            for (int i = 1; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    return a[i] > b[i];
                }
            }
            return a[0] < b[0];
        });
        stringstream ss;
        for (auto &v : count) {
            char c = v[0] + 'A';
            if (has[v[0]]) {
                ss << c;
            }
        }
        return ss.str();
    }
};