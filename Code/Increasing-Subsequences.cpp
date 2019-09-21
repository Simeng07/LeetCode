class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2) {
            return result;
        }
        vector<int> current;
        helper(nums, 0, current);
        return result;
    }
    
    void helper(vector<int> &nums, int start, vector<int> &current) {
        bool visited[201] = {false}; // 某一轮中，出现重复数字时，前面必然已经遍历过了
        for (int i = start; i < nums.size(); i++) {
            if (!visited[nums[i] + 100] && (current.empty() || nums[i] >= current.back())) {
                current.emplace_back(nums[i]);
                if (current.size() > 1) {
                    result.emplace_back(current);
                }
                helper(nums, i + 1, current);
                current.pop_back();
                visited[nums[i] + 100] = true;
            }
        }
    }
};