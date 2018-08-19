class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tmp = max(nums[i], tmp + nums[i]);
            result = max(result, tmp);
        }
        return result;
    }
};