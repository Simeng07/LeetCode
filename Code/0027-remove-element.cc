class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int p1 = 0;
        int p2 = nums.size() - 1;
        while (true) {
            while (nums[p1] != val) {
                p1++;
                if (p1 == nums.size()) {
                    return p1;
                }
            }
            while (nums[p2] == val) {
                p2--;
                if (p2 == -1) {
                    return 0;
                }
            }
            if (p1 > p2) {
                return p1;
            }
            nums[p1] = nums[p2];
            nums[p2] = val;
        }
    }
};