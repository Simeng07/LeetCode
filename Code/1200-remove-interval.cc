class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        if (toBeRemoved.size() == 0) {
            return intervals;
        }
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] <= toBeRemoved[0] || intervals[i][0] >= toBeRemoved[1]) {
                result.push_back(intervals[i]);
            } else {
                if (intervals[i][0] >= toBeRemoved[0]) {
                    if (intervals[i][1] >= toBeRemoved[1]) {
                        intervals[i][0] = toBeRemoved[1];
                        i--;
                    } else {
                        //
                    }
                } else {
                    if (intervals[i][1] >= toBeRemoved[1]) {
                        result.push_back({intervals[i][0], toBeRemoved[0]});
                        intervals[i][0] = toBeRemoved[1];
                        i--;
                    } else {
                        result.push_back({intervals[i][0], toBeRemoved[0]});
                    }
                }
            }
        }
        return result;
    }
};