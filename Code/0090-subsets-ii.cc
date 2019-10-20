class Solution {
    vector<vector<int> > result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        helper(tmp, nums, 0);
        return result;
    }
    // backtracking
    void helper(vector<int>& tmp, vector<int>& nums, int n) {
        result.push_back(tmp);
        for (int i = n; i < nums.size(); i++) {
            if (i == n || nums[i] != nums[i - 1]) {
                tmp.push_back(nums[i]);
                helper(tmp, nums, i + 1);
                tmp.pop_back();
            }
        }
    }
};