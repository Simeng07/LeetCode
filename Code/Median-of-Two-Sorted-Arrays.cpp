class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return the average of kth and (k+1)th num of m+n is even
        int k = (nums1.size() + nums2.size()) / 2 + 1;
        int a = kth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k);
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            int b = kth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k - 1);
            return ((double)a + b) / 2;
        }
        return a;
    }
        
    int kth(vector<int>& nums1, int start1, int size1, vector<int>& nums2, int start2, int size2, int k) {
        // size is the length of size~end
        if (size1 > size2) return kth(nums2, start2, size2, nums1, start1, size1, k);
        if (size1 == 0) return nums2[start2 + k - 1];
        if (k == 1) return min(nums1[start1], nums2[start2]);
        // maybe k/2 is larger than size1
        int i = min(k / 2, size1);
        int j = k - i;
        // delete the smaller i or j items
        if (nums1[start1 + i - 1] > nums2[start2 + j - 1]) return kth(nums1, start1, size1, nums2, start2 + j, size2 - j, k - j);
        return kth(nums1, start1 + i, size1 - i, nums2, start2, size2, k - i);
    }
};