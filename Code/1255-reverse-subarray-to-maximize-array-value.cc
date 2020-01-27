class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int smallestBigger = max(nums[0], nums[1]);
        int biggestSmaller = min(nums[0], nums[1]);
        int origin = smallestBigger - biggestSmaller;
        for (int i = 1; i < nums.size() - 1; i++) {
            smallestBigger = min(smallestBigger, max(nums[i], nums[i + 1])); // smallest bigger one
            biggestSmaller = max(biggestSmaller, min(nums[i], nums[i + 1])); // biggest smaller one
            origin += abs(nums[i] - nums[i + 1]);
        }
        int diff = max(0, 2 * (biggestSmaller - smallestBigger));
        for (int i = 1; i < nums.size() - 1; i++) {
            diff = max(diff, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
            diff = max(diff, abs(nums[size - 1] - nums[i]) - abs(nums[i + 1] - nums[i]));
        }
        return diff + origin;
    }
};