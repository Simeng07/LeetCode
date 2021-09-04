class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i];
            right[n - 1 - i] = right[n - i] + nums[n - 1 - i];
        }
        if (right[1] == 0) {
            return 0;
        }
        for (int i = 0; i < n - 1; i++) {
            if (left[i] == right[i]) {
                return i;
            }
        }
        if (left[n - 2] == 0) {
            return n - 1;
        }
        return -1;
    }
};