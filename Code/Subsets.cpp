class Solution {
public:
    // bit manipulation.
    // (backtracking works, too)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < pow(2, nums.size()); i++) {
            vector<int> tmpv;
            for (int k = 0; k < nums.size(); k++) {
                int j = 1 << k;
                // (i & j)
                if ((i & j) != 0) {
                    tmpv.push_back(nums[k]);
                }
            }
            sort(tmpv.begin(), tmpv.end());
            result.push_back(tmpv);
        }
        return result;
    }
};