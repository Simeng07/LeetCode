class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        k--;
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int i = 0; i + k < nums.size(); i++) {
            result = min(result, nums[i + k] - nums[i]);
        }
        return result;
    }
};