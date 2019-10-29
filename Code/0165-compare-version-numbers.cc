class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        vector<int> v1, v2;
        string tmp;
        while (getline(ss1, tmp, '.')) {
            v1.push_back(stoi(tmp));
        }
        while (getline(ss2, tmp, '.')) {
            v2.push_back(stoi(tmp));
        }
        for (int i = 0; i < min(v1.size(), v2.size()); i++) {
            if (v1[i] < v2[i]) {
                return -1;
            }
            if (v1[i] > v2[i]) {
                return 1;
            }
        }
        for (int i = v1.size(); i < v2.size(); i++) {
            if (v2[i] != 0) {
                return -1;
            }
        }
        for (int i = v2.size(); i < v1.size(); i++) {
            if (v1[i] != 0) {
                return 1;
            }
        }
        return 0;
    }
};