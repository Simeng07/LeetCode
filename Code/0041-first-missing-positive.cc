class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums[i]) {
                continue;
            }
            int tmp = nums[i];
            while(tmp >= 1 && tmp <= nums.size() && tmp != nums[tmp - 1]) {
                swap(tmp, nums[tmp - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};