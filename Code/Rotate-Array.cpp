class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = nums.size();
        k = k % count;
        if (k == 0) {
            return;
        }
        reverse(nums.begin(), nums.begin() + count - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};