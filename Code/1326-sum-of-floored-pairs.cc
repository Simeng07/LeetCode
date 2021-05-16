class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int count[200001] = {0};
        int maxn = 0;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            maxn = max(maxn, nums[i]);
        }
        for (int i = 1; i < 200001; i++) {
            count[i] += count[i - 1];
        }
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; nums[i] * j <= maxn; j++) {
                result += j * (count[(j + 1) * nums[i] - 1] - count[j * nums[i] - 1]);
                result %= 1000000007;
            }
        }
        return result;
    }
};