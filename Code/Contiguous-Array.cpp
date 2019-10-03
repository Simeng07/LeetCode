class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int sum = 0, result = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            } else {
                result = max(result, i - m[sum]);
            }
        }
        return result;
    }
};