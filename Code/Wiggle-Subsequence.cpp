class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int result = 1, status = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 0) {
                if (status != 1) {
                    status = 1;
                    result++;
                }
            } else if (nums[i] - nums[i - 1] < 0) {
                if (status != -1) {
                    status = -1;
                    result++;
                }
            }
        }
        return result;
    }
};