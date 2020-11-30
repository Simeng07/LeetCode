class Solution {
    // Longest Increasing Subsequence
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        // left to right:
        for (int i = 0; i < n; i++) {
            left[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        
        // right to left
        for (int i = n - 1; i >= 0; i--) {
            right[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (left[i] != 1 && right[i] != 1) {
                result = min(result, n - (left[i] + right[i] - 1));
            }
        }
        
        return result;
    }
};