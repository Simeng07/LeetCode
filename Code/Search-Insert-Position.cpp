class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int p = 0;
        if (nums[p] >= target) {
            return p;
        }
        int q = nums.size() - 1;
        if (nums[q] == target) {
            return q;
        }
        if (nums[q] < target) {
            return q + 1;
        }
        while (p < q) {
            int mid = p + (q - p) / 2;
            if (mid == p) {
                return q;
            }
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                p = mid;
            } else {
                q = mid;
            }
        }
    }
};