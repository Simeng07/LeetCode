class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i - k - 1]);
            // -t <= x - mums[i] <= t
            // 1. x >= nums[i] - t
            auto p = s.lower_bound(nums[i] - (long long)t);
            // 2. x <= nums[i] + t
            if (p != s.end() && *p - nums[i] <= t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};