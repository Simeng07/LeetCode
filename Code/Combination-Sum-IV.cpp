class Solution {
    unordered_map<int, int> m;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        if (m.find(target) != m.end()) {
            return m[target];
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) {
                result += combinationSum4(nums, target - nums[i]);
            }
        }
        m[target] = result;
        return result;
    }
};