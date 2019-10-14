class Solution {
public:
    int jump(vector<int>& nums) {
        // when pass by the current max point, result++
        int result = 0;
        int lastJumpMax = 0;
        int currentJumpMax = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currentJumpMax = max(i + nums[i], currentJumpMax);
            if (currentJumpMax == i) return -1;
            if (i == lastJumpMax) {
                result++;
                lastJumpMax = currentJumpMax;
            }
        }
        return result;
    }
};