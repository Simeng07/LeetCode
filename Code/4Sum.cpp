class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int k = j + 1; int l = nums.size() - 1;
                while (k < l) {
                    int tmpSum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (tmpSum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k + 1 < l && nums[k] == nums[k + 1]) k++;
                        while (k + 1 < l && nums[l] == nums[l - 1]) l--;
                    }
                    if (tmpSum <= target) k++;
                    if (tmpSum >= target) l--;
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};