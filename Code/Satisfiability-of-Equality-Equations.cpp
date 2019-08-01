class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<unordered_set<char> > sets;
        for (auto equation : equations) {
            char a = equation[0];
            char b = equation[3];
            if (equation[1] == '=') {
                int ia = -1, ib = -1;
                for (int i = 0; i < sets.size(); i++) {
                    if (ia == -1 && sets[i].find(a) != sets[i].end()) {
                        ia = i;
                    }
                    if (ib == -1 && sets[i].find(b) != sets[i].end()) {
                        ib = i;
                    }
                    if (ia != -1 && ib != -1) {
                        break;
                    }
                }
                
                if (ia != -1) {
                    if (ib != -1) {
                        if (ia == ib) {
                            continue;
                        }
                        // 把b和sb的全弄到sa
                        for (auto c : sets[ib]) {
                            sets[ia].insert(c);
                        }
                        sets[ia].insert(b);
                        sets.erase(sets.begin() + ib);
                    } else {
                        // 把b加到sa
                        sets[ia].insert(b);
                    }
                } else {
                    if (ib != -1) {
                        // 把a加到sb
                        sets[ib].insert(a);
                    } else {
                        // 新增一个只包含ab的set
                        sets.push_back({a, b});
                    }
                }
            } else {
                if (a == b) {
                    return false;
                }
            }
        }
        for (auto equation : equations) {
            if (equation[1] == '!') {
                char a = equation[0];
                char b = equation[3];
                int ia = -1, ib = -1;
                for (int i = 0; i < sets.size(); i++) {
                    if (ia == -1 && sets[i].find(a) != sets[i].end()) {
                        ia = i;
                    }
                    if (ib == -1 && sets[i].find(b) != sets[i].end()) {
                        ib = i;
                    }
                    if (ia != -1 && ib != -1) {
                        break;
                    }
                }
                
                if (ia != -1 && ib != -1 && ia == ib) {
                    return false;
                }
            }
        }
        return true;
    }
};