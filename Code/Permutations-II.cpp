class Solution {
    set<vector<int>> s;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums, 0);
        vector<vector<int>> result;
        result.assign(s.begin(), s.end());
        return result;
    }
    
    void helper(vector<int>& nums, int begin) {
        if (begin == nums.size() - 1) {
            s.insert(nums);
            return;
        }
        unordered_set<int> has;
        for (int i = begin; i < nums.size(); i++) {
            if (has.find(nums[i]) == has.end()) {
                has.insert(nums[i]);
                swap(nums[begin], nums[i]);
                helper(nums, begin + 1);
                swap(nums[begin], nums[i]);
            }
        }
    }
};