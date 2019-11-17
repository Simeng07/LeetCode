class Solution {
    int insertAndCountSmaller(vector<int>& nums, int index) {
        if (index == nums.size() - 1) return 0;
        if (nums[index] <= nums[index + 1]) return 0;
        if (nums[index] > nums[nums.size() - 1]) {
            nums.insert(nums.begin() + nums.size(), nums[index]);
            nums.erase(nums.begin() + index);
            return nums.size() - 1 - index;
        }
        // 找到nums[index]应该插入的位置，算出count，之后插进去
        int low = index + 1;
        int high = nums.size() - 1;
        int middle = low + (high - low) / 2;
        while (low < high - 1) {
            if (nums[middle] >= nums[index]) {
                high = middle;
            } else {
                low = middle;
            }
            middle = low + (high - low) / 2;
        }
        nums.insert(nums.begin() +  low + 1, nums[index]);
        nums.erase(nums.begin() + index);
        return low - index;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result.insert(result.begin(), insertAndCountSmaller(nums, i));
        }
        return result;
    }
};