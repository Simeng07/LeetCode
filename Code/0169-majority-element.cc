class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                result = nums[i];
                count = 1;
            } else {
                count += (result == nums[i] ? 1 : -1);
            }
        }
        return result;
    }
};