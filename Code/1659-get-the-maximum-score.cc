class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long n1 = 0, n2 = 0;
        int p = nums1.size() - 1, q = nums2.size() - 1;
        while (p >= 0 && q >= 0) {
            if (nums1[p] > nums2[q]) {
                n1 += nums1[p--];
            } else if (nums1[p] < nums2[q]) {
                n2 += nums2[q--];
            } else {
                n2 = n1 = nums1[p] + max(n1, n2);
                p--;
                q--;
            }
        }
        while (p >= 0) {
            n1 += nums1[p--];
        }
        while (q >= 0) {
            n2 += nums2[q--];
        }
        return max(n1, n2) % 1000000007;
    }
};