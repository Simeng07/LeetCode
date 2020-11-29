class Solution {
    // stack o(n):
    // https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        });
        
        vector<int> result(k, -1);
        int index = 0; // index for v
        int resultp = 0, resultq = k; // result index
        int numsp = -1, numsq = n; // nums index
        
        while (k > 0) {
            if (v[index].second >= numsq || v[index].second <= numsp) {
                index++;
                continue;
            }
            
            // add all elements after v[index].second
            if (numsq - v[index].second == k) {
                for (int i = 0; i < k; i++) {
                    result[resultp + i] = nums[v[index].second + i];
                }
                return result;
            }
            
            if (numsq - v[index].second > k) {
                // add the min element
                result[resultp] = v[index].first;
                resultp++;
                k--;
                numsp = max(numsp, v[index].second);
            } else {
                // add all elements after the min element to the right part of the result vector
                resultq -= (numsq - v[index].second);
                k -= (numsq - v[index].second);
                for (int i = 0; i < numsq - v[index].second; i++) {
                    result[resultq + i] = nums[v[index].second + i];
                }
                numsq = v[index].second;
            }
            index++;
        }
        
        return result;
    }
};