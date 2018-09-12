class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minNum = min(minNum, nums[i]);
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += (nums[i] - minNum);
        }
        return result;
    }
};