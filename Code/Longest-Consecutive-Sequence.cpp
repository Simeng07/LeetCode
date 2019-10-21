class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (m.find(num) == m.end()) {
                // wrong: m[num] = m[num - 1] + 1 + m[num + 1];
                int left = (m.find(num - 1) != m.end()) ? m[num - 1] : 0;
                int right = (m.find(num + 1) != m.end()) ? m[num + 1] : 0;
                m[num] = left + right + 1;
                m[num - left] = m[num];
                m[num + right] = m[num];
                result = max(result, m[num]);
            }
        }
        return result;
    }
};