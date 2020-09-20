class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            diff += nums[i];
        }
        diff %= p;
        if (diff == 0) {
            return 0;
        }
        
        int result = nums.size();
        unordered_map<int, int> lastIndex;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= p;
            int gap = (sum + p - diff) % p;
            if (lastIndex.find(gap) != lastIndex.end()) {
                result = min(result, i - lastIndex[gap]);
            } else if (gap == 0) {
                result = min(result, i + 1); // i - (-1)
            }
            lastIndex[sum] = i;
        }
        
        return (result == nums.size() ? -1 : result);
    }
};