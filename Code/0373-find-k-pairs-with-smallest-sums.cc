class Solution {
    bool flag;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) {
            flag = true;
            return kSmallestPairs(nums2, nums1, k);
        }
        vector<vector<int>> result;
        if (nums1.size() * nums2.size() == 0) return result;
        int a[nums1.size()] = {0};
        for (int i = 0; i < k; i++) {
            int tmpMin = INT_MAX;
            int tmpIndex = 0;
            for (int j = 0; j < nums1.size(); j++) {
                if (a[j] >= nums2.size()) continue;
                if (nums1[j] + nums2[a[j]] < tmpMin) {
                    tmpMin = nums1[j] + nums2[a[j]];
                    tmpIndex = j;
                }
            }
            if (tmpMin == INT_MAX) break;
            if (flag) {
                result.push_back({nums2[a[tmpIndex]], nums1[tmpIndex]});
            } else {
                result.push_back({nums1[tmpIndex], nums2[a[tmpIndex]]});
            }
            a[tmpIndex]++;
        }
        return result;
    }
};