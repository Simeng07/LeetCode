class Solution {
    bool result = false;
    int eachSum = 0;
    vector<bool> used;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) {
            return false;
        }
        eachSum = total / k;
        used = vector<bool>(size, false);
        helper(nums, 0, 0, k);
        return result;
    }
    
    void helper(vector<int>& nums, int currentIndex, int currentSum, int remainSets) {
        if (result) {
            return;
        }
        if (remainSets == 0) {
            result = true;
            return;
        }
        for (int i = currentIndex; i < nums.size() && !result; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            int tmpSum = currentSum + nums[i];
            if (tmpSum == eachSum) {
                helper(nums, 0, 0, remainSets - 1);
            } else if (tmpSum < eachSum) {
                helper(nums, i + 1, tmpSum, remainSets);
            }
            used[i] = false;
        }
    }
};