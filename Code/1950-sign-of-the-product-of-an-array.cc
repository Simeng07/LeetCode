class Solution {
public:
    int arraySign(vector<int>& nums) {
        int result = 1;
        for (auto num : nums) {
            if (num < 0) {
                result *= -1;
            }
            if (num == 0) {
                return 0;
            }
        }
        return result;
    }
};