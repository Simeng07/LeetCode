class Solution {
public:
    int rob(vector<int>& nums) {
        int current = 0;
        int rob = 0;
        int norob = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = norob;
            norob = max(norob, rob);
            rob = tmp + nums[i];
        }
        return max(rob, norob);
    }
};