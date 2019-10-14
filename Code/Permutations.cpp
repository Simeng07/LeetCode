class Solution {
    vector<vector<int> > result;
public:
    // backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return result;
    }
    void helper(vector<int>& nums, int begin) {
        if (begin == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            // swap
            swap(nums[begin], nums[i]);
            helper(nums, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
};