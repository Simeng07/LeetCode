class Solution {
    bool result = false;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        int total = 0;
        for (auto num : nums) {
            total += num;
        }
        if (total % k != 0) {
            return false;
        }
        int sum = total / k;
        sort(nums.begin(), nums.end());
        if (sum < nums.back()) {
            return false;
        }
        vector<int> sums(k, sum);
        helper(nums, sums, nums.size() - 1);
        
        return result;
    }
    
    void helper(vector<int>& nums, vector<int>& sums, int index) {
        if (result) {
            return;
        }
        if (accumulate(sums.begin(), sums.end(), 0) == 0) {
            result = true;
            return;
        }
        if (index < 0 || index >= nums.size()) {
            return;
        }
        int current = nums[index];
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] - current >= 0) {
                sums[i] -= current;
                helper(nums, sums, index - 1);
                sums[i] += current;
            }
        }
    }
};