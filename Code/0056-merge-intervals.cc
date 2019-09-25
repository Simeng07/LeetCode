class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int begin, end;
        if (intervals.size() > 0) {
            if (intervals[0].size() > 0) {
                begin = intervals[0][0];
                end = intervals[0][1];
            } else {
                return result;
            }
        } else {
            return result;
        }
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                result.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({begin, end});
        return result;
    }
};