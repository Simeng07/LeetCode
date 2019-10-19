class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) return;
        int p = 0;  // the first index after 0
        int q = 0;  // current 
        int r = nums.size() - 1;  // the first index before 2
        // <=, not !=
        while(q <= r) {
            if (nums[q] == 0) {
                if (q == p) {
                    p++;
                    q++;
                    continue;
                }
                swap(nums[p++], nums[q++]);
            }else if (nums[q] == 2) {
                swap(nums[r--], nums[q]);
            }else {
                q++;
            }
        }
    }
};