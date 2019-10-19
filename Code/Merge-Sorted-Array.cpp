class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            for (int i = 0; i < n; i++) nums1[i] = nums2[i];
            return;
        }
        int p = m + n - 1;
        while (m != 0 && n != 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[p] = nums1[m - 1];
                p--;
                m--;
            } else {
                nums1[p] = nums2[n - 1];
                p--;
                n--;
            }
        }
        if (n == 0) return;
        for (p; p >= 0; p--) {
            nums1[p] = nums2[n - 1];
            n--;
        }
    }
};