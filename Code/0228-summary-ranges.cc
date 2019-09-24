class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0) {
            return result;
        }
        int begin = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (begin == end) {
                    result.push_back(to_string(begin));
                } else {
                    result.push_back(to_string(begin) + "->" + to_string(end));
                }
                begin = nums[i];
                end = nums[i];
            }
        }
        if (begin == end) {
            result.push_back(to_string(begin));
        } else {
            result.push_back(to_string(begin) + "->" + to_string(end));
        }
        return result;
    }
};