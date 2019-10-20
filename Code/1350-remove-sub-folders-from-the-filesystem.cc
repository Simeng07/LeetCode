class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if (folder.size() == 1) {
            return folder;
        }
        vector<string> result;
        sort(folder.begin(), folder.end());
        result.push_back(folder[0]);
        string last = folder[0];
        for (int i = 1; i < folder.size(); i++) {
            if (folder[i].length() < last.length()) {
                result.push_back(folder[i]);
                last = folder[i];
            } else if (folder[i].length() == last.length()) {
                if (folder[i] != folder[i - 1]) {
                    result.push_back(folder[i]);
                    last = folder[i];
                }
            } else {
                if (strncmp(folder[i].c_str(), last.c_str(), last.length()) == 0) {
                    if (folder[i][last.length()] != '/') {
                        result.push_back(folder[i]);
                        last = folder[i];
                    }
                } else {
                    result.push_back(folder[i]);
                    last = folder[i];
                }
            }
        }
        return result;
    }
};