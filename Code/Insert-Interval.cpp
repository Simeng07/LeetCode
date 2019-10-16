class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        for (i; i < intervals.size(); i++) {
            if (intervals[i][0] > newInterval[1]) {
                break;
            } else if (intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        result.push_back(newInterval);
        for (i; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};