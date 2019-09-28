class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() == 0) {
            return "";
        }
        
        stringstream ss;
        ss << path;
        deque<string> dq;
        string word;
        while (getline(ss, word, '/')) {
            if (word == "" || word == ".") {
                continue;
            } else {
                if (word == "..") {
                    if (!dq.empty()) {
                        dq.pop_back();
                    }
                } else {
                    dq.push_back(word);
                }
            }
        }
        
        stringstream out;
        for (auto dir : dq) {
            out << "/" << dir;
        }
        
        string result = "";
        out >> result;
        
        if (result == "") {
            result = "/";
        }
        
        return result;
    }
};