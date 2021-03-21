class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current += nums[i];
                result = max(result, current);
            } else {
                current = nums[i];
            }
        }
        result = max(result, current);
        return result;
    }
};