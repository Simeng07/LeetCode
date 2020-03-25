class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin());
        }
        return result;
    }
};