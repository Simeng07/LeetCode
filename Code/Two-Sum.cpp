class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n), 使用unordered_map，基于hash
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator it = map.find(target - nums[i]); // auto it = xxx;
            if (it != map.end()) {
                return {it->second, i};
            } else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
    // MM：O(n^2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 result.push_back(i);
    //                 result.push_back(j);
    //             }
    //         }
    //     }
    //     return result;
    // }
};