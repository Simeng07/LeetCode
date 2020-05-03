class Solution {
    int m[1024][41];
    int personMask;
public:
    int numberWays(vector<vector<int>>& hats) {
        int personCount = hats.size();
        personMask = (1 << personCount) - 1;
        memset(m, -1, sizeof(m));
        vector<vector<int>> mHats(41, vector<int>());
        for (int i = 0; i < personCount; i++) {
            for (int j = 0; j < hats[i].size(); j++) {
                mHats[hats[i][j]].push_back(i);
            }
        }
        return (int)helper(mHats, 0, 0);
    }
    
    long long helper(vector<vector<int>>& hats, int index, int mask) {
        if (index == hats.size()) {
            if (mask == personMask) {
                return 1;
            } else {
                return 0;
            }
        }
        if (m[mask][index] >= 0) {
            return m[mask][index];
        }
        long long result = 0;
        for (int i = 0; i < hats[index].size(); i++) {
            int current = (1 << hats[index][i]);
            if ((mask | current) != mask) {
                result += helper(hats, index + 1, (mask | current));
                result %= 1000000007;
            }
        }
        result += helper(hats, index + 1, mask);
        result %= 1000000007;
        m[mask][index] = result;
        return result;
    }
};