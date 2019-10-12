class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i], j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int b = nums[j], c = nums[k];
                int tmpSum = a + b + c;
                if (tmpSum == target) return target;
                if (tmpSum < target) {
                    j++;
                } else {
                    k--;
                }
                if (abs(tmpSum - target) < abs(result - target)) result = tmpSum;
            }
        }
        return result;
    }
};