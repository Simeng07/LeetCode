class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p = 0, q = 0;
        while (p != g.size() && q != s.size()) {
            if (g[p] <= s[q]) {
                p++;
            }
            q++;
        }
        return p;
    }
};