class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.size() == 0) return result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()) {
            int a = nums[i], j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int b = nums[j], c = nums[k];
                if (a + b + c == 0) {
                    result.push_back({a, b, c});
                    while(j + 1 < k && nums[j + 1] == b) j++;
                    while(j + 1 < k && nums[k - 1] == c) k--;
                }
                if (a + b + c <= 0) j++;
                if (a + b + c >= 0) k--;
            }
            while (i < nums.size() && nums[i] == a) i++;
        }
        return result;
    }
};