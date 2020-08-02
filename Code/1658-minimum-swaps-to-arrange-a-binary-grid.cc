class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int right[200];
        int n = grid.size();
        unordered_map<int, set<int>> m;
        for (int i = 0; i < n; i++) {
            int index = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    index = j;
                }
            }
            right[i] = index;
            if (index == -1) {
                index = 0;
            }
            m[index].insert(i);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += m[i].size();
            if (count < i + 1) {
                return -1;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int index = *(m[i].begin());
            m[i].erase(index);
            for (int j = index - 1; j >= i; j--) {
                result++;
                right[j + 1] = right[j];
                m[right[j]].erase(j);
                m[right[j]].insert(j + 1);
            }
            m[i + 1].insert(m[i].begin(), m[i].end());
        }
        return result;
    }
};