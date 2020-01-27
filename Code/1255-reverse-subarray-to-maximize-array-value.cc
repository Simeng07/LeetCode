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
        int diff = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            // the origin value
            origin += abs(nums[i] - nums[i + 1]);
            // reverse inner part
            smallestBigger = min(smallestBigger, max(nums[i], nums[i + 1])); // smallest bigger one
            biggestSmaller = max(biggestSmaller, min(nums[i], nums[i + 1])); // biggest smaller one
            // reverse edge part
            diff = max(diff, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
            diff = max(diff, abs(nums[size - 1] - nums[i]) - abs(nums[i + 1] - nums[i]));
        }
        diff = max(diff, 2 * (biggestSmaller - smallestBigger));
        return diff + origin;
    }
};