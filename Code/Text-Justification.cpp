class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.size() == 0) return result;
        if (words.size() == 1) {
            string s = words[0];
            for (int i = s.length(); i < maxWidth; i++) s += " ";
            result.push_back(s);
            return result;
        }
        
        vector<string> tmp({words[0]});
        int currentLength = words[0].length();
        
        for (int i = 1; i < words.size(); i++) {
            if (currentLength + 1 + words[i].length() <= maxWidth) {
                // 放进同一行
                tmp.push_back(words[i]);
                currentLength += 1 + words[i].length();
                // 最后一个单词
                if (i == words.size() - 1) {
                    string s = "";
                    for (int j = 0; j < tmp.size(); j++) {
                        s += tmp[j];
                        if (j != tmp.size() - 1) s += " ";
                        else while(s.length() < maxWidth) s += " ";
                    }
                    result.push_back(s);
                    return result;
                }
            } else {
                // 另起一行
                string s = "";
                if (tmp.size() == 1) {
                    // 上一行只有一个单词
                    s += tmp[0];
                    while(s.length() < maxWidth) s += " ";
                } else {
                    int spaces = maxWidth - currentLength;
                    int eachSpace = spaces / (tmp.size() - 1) + 1;
                    int firstN = spaces % (tmp.size() - 1);
                    for (int j = 0; j < firstN; j++) {
                        s += tmp[j];
                        for (int k = 0; k <= eachSpace; k++) s += " ";
                    }
                    for (int j = firstN; j < tmp.size() - 1; j++) {
                        s += tmp[j];
                        for (int k = 0; k < eachSpace; k++) s += " ";
                    }
                    s += tmp[tmp.size() - 1];
                }
                result.push_back(s);
                // 这一行只有一个单词
                if (i == words.size() - 1) {
                    string ss = words[i];
                    while(ss.length() < maxWidth) ss += " ";
                    result.push_back(ss);
                    return result;
                }
                // 另起一行
                tmp.clear();
                tmp.push_back(words[i]);
                currentLength = words[i].length();
            }
        }
        return result;
    }
};