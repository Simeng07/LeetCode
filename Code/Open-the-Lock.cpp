class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool deadend[10000] = {false};
        int itarget = stoi(target);
        
        for (auto d : deadends) {
            if (stoi(d) == itarget || stoi(d) == 0) {
                return -1;
            }
            deadend[stoi(d)] = true;
        }
        
        vector<unordered_set<int>> v(2);
        v[0] = {0};
        
        bool has[10000] = {false};
        has[0] = true;
        
        int move = 0;
        
        while (true) {
            int old = move & 1;
            move++;
            int current = move & 1;
            v[current].clear();
            for (auto num : v[old]) {
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j <= 1; j += 2) {
                        int tmp = cal(num, i, j);
                        if (tmp == itarget) {
                            return move;
                        }
                        if (has[tmp]) {
                            continue;
                        } else {
                            has[tmp] = true;
                        }
                        if (deadend[tmp]) {
                            continue;
                        }
                        v[current].insert(tmp);
                    }
                }
                if (v[current].size() == 0) {
                    return -1;
                }
            }
        }
        
        return -1;
    }
    
    int cal(int num, int pos, int act) {
        int fac = pow(10, pos);
        int result = 0;
        if (act == 1) {
            if (num % (10 * fac) < 9 * fac) {
                result = num + fac;
            } else {
                result = num - 9 * fac;
            }
        } else {
            if (num % (10 * fac) < fac) {
                result = num + 9 * fac;
            } else {
                result = num - fac;
            }
        }
        return result;
    }
};