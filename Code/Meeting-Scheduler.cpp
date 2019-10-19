class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> result;
        int i = 0, j = 0, size1 = slots1.size(), size2 = slots2.size();
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        while (true) {
            if (i > size1 - 1 || j > size2 - 1) {
                return result;
            }
            if (slots1[i][0] <= slots2[j][0]) {
                if (slots2[j][0] + duration <= min(slots1[i][1], slots2[j][1])) {
                    return {slots2[j][0], slots2[j][0] + duration};
                }
                i++;
            } else {
                if (slots1[i][0] + duration <= min(slots1[i][1], slots2[j][1])) {
                    return {slots1[i][0], slots1[i][0] + duration};
                }
                j++;
            }
        }
        return result;
    }
};