class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int current = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current++;
            } else {
                if (current > result) {
                    result = current;
                }
                current = 0;
            }
        }
        if (current > result) {
            result = current;
        }
        return result;
    }
};