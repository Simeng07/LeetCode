class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -pow(10ll, 10), high = pow(10ll, 10) + 1;
        while (low < high) {
            long long middle = low + (high - low) / 2;
            if (helper(middle, nums1, nums2) < k) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        return low;
    }
    
    long long helper(double value, vector<int>& nums1, vector<int>& nums2) {
        long long result = 0;
        for (auto &x : nums1) {
            if (x < 0) {
                result += nums2.end() - lower_bound(nums2.begin(), nums2.end(), ceil(value / x));
            } else if (x == 0) {
                if (value >= 0) {
                    result += nums2.size();
                }
            } else {
                result += upper_bound(nums2.begin(), nums2.end(), floor(value / x)) - nums2.begin();
            }
        }
        return result;
    }
};