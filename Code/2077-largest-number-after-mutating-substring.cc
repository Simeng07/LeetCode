class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string result = "";
        bool start = false;
        for (int i = 0; i < num.size(); i++) {
            if (change[num[i] - '0'] > (num[i] - '0')) {
                if (!start) {
                    start = true;
                }
                result += to_string(change[num[i] - '0']);
            }
            if (change[num[i] - '0'] == (num[i] - '0')) {
                result += num[i];
            }
            if (change[num[i] - '0'] < (num[i] - '0')) {
                if (start) {
                    result += num.substr(i);
                    return result;
                } else {
                    result += num[i];
                }
            }
        }
        return result;
    }
};