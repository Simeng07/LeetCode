class Solution {
    int dp[500][500] = {0};
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp[0][0] = nums1[0] * nums2[0];
        if (dp[0][0] < 0) {
            dp[0][0] = 0;
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                } else {
                    dp[i][j] = max(dp[i][j], nums1[0] * nums2[j]);
                }
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                } else {
                    dp[i][j] = max(dp[i][j], nums2[0] * nums1[i]);
                }
                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
                }
            }
        }
        if (dp[nums1.size() - 1][nums2.size() - 1] == 0) {
            return max((*max_element(nums1.begin(), nums1.end())) * (*min_element(nums2.begin(), nums2.end())), (*min_element(nums1.begin(), nums1.end()) * (*max_element(nums2.begin(), nums2.end()))));
        } else {
            return dp[nums1.size() - 1][nums2.size() - 1];
        }
    }
};