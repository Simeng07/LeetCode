class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int result = nums[k];
        int minn = nums[k];
        int i = k, j = k, n = nums.size();
        while (i > 0 || j < n - 1) {
            if ((i > 0 ? nums[i - 1] : 0) < (j < n - 1 ? nums[j + 1] : 0)) {
                minn = min(minn, nums[++j]);
            } else {
                minn = min(minn, nums[--i]);
            }
            result = max(result, minn * (j - i + 1));
        }
        return result;
    }
};