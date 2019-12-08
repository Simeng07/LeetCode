class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int begin = 1;
        int end = nums.back();
        int middle = begin + (end - begin) / 2;
        while (begin != middle && middle != end) {
            int current = helper(nums, middle);
            if (current > threshold) {
                begin = middle;
            } else {
                end = middle;
            }
            middle = begin + (end - begin) / 2;
        }
        if (helper(nums, begin) <= threshold) {
            return begin;
        }
        if (helper(nums, middle) <= threshold) {
            return middle;
        }
        if (helper(nums, end) <= threshold) {
            return end;
        }
        return begin;
    }
    
    int helper(vector<int>& nums, int current) {
        if (nums.size() == 0) {
            return 0;
        }
        int minn = nums[0];
        int maxn = nums.back();
        int result = 0;
        int lastIndex = 0;
        for (int i = 1; i <= maxn / current + 1; i++) {
            int index = upper_bound(nums.begin(), nums.end(), current * i) - nums.begin();
            result += (index - lastIndex) * i;
            lastIndex = index;
        }
        return result;
    }
};