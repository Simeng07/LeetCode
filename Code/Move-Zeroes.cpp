class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int n = nums.size();
        while (nums[p] != 0 && p < n) {
            p++;
        }
        if (p == nums.size()) {
            return;
        }
        int q = p;
        while (true) {
            while (nums[p] != 0 && p < n) {
                p++;
            }
            if (p == n) {
                return;
            }
            while (nums[q] == 0 && q < n) {
                q++;
            }
            if (q == n) {
                return;
            }
            nums[p] = nums[q];
            nums[q] = 0;
            p++;
            q++;
        }
    }
};