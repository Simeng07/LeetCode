class Solution {
public:
    // https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/953078/C%2B%2B-Prefix-sum-O(n-%2B-limit)
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v(limit * 2 + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            v[2] += 2;
            v[min(a, b) + 1]--;
            v[a + b]--;
            v[a + b + 1]++;
            v[max(a, b) + limit + 1]++;
        }
        int result = INT_MAX, current = 0;
        for (int i = 2; i <= limit * 2; i++) {
            current += v[i];
            result = min(result, current);
        }
        return result;
    }
    
    // TLE:
//     int minMoves(vector<int>& nums, int limit) {
//         int result = INT_MAX;
//         int n = nums.size();
//         unordered_map<int, int> m;
//         vector<pair<int, int>> v(n / 2);
//         for (int i = 0; i < n / 2; i++) {
//             m[nums[i] + nums[n - 1 - i]]++;
//             v[i] = {min(nums[i], nums[n - 1 - i]) + 1, max(nums[i], nums[n - 1 - i]) + limit};
//         }
        
//         priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int ,int>>> count;
//         for (auto &it : m) {
//             count.push({it.second, it.first});
//         }
//         while (!count.empty()) {
//             auto &p = count.top();
//             count.pop();
//             if (p.first < n / 2 - result) {
//                 return result;
//             }
//             int change = helper(nums, v, p.second);
//             result = min(change, result);
//         }
//         return result;
//     }
    
//     int helper(vector<int>& nums, vector<pair<int, int>> &v, int k) {
//         int result = 0;
//         int n = nums.size();
//         for (int i = 0; i < n / 2; i++) {
//             if (nums[i] + nums[n - 1 - i] == k) {
//                 continue;
//             }
//             if (v[i].first > k || v[i].second < k) {
//                 result += 2;
//             } else {
//                 result += 1;
//             }
//         }
//         return result;
//     }
};