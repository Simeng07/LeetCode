class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() == 1 && abs(nums[0] == 1)) {
            return true;
        }
        int gcd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = __gcd(nums[i], gcd);
                if (tmp == 1) {
                    return true;
                }
            gcd = tmp;
        }
        return false;
    }
};