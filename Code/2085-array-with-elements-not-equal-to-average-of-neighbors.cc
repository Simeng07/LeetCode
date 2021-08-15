class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i * 2;
            if (j >= n) {
                if (n % 2 == 0) {
                    j -= (n - 1);
                } else {
                    j -= n;
                }
            }
            result[j] = nums[i];
        }
        return result;
    }
};