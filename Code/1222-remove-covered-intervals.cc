class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return 1;
        }
        sort(intervals.begin(), intervals.end());
        int begin = intervals[0][0];
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] == begin) {
                end = intervals[i][1];
            } else if (intervals[i][0] < end) {
                if (intervals[i][1] > end) {
                    begin = intervals[i][0];
                    end = intervals[i][1];
                    count++;
                }
            } else {
                begin = intervals[i][0];
                end = intervals[i][1];
                count++;
            }
        }
        return count;
    }
};