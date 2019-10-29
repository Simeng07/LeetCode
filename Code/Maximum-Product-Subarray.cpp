class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0], pos = nums[0], neg = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = pos;
            pos = max(nums[i], max(nums[i] * pos, nums[i] * neg));
            neg = min(nums[i], min(nums[i] * tmp, nums[i] * neg));
            result = max(result, pos);
        }
        return result;
    }
};