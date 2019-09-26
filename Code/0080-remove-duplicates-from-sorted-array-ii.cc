class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int current = 1;
        bool has = false;
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[current - 1]) {
                if (!has) {
                    nums[current] = nums[i];
                    current++;
                    has = true;
                } else {
                    // do nothing
                }
            } else {
                nums[current] = nums[i];
                current++;
                has = false;
            }
        }
        return current;
    }
};