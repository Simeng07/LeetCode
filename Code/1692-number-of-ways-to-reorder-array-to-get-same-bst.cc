class Solution {
    int cdp[1000][1000] = {0};
    int mod = 1000000007;
public:
    int numOfWays(vector<int>& nums) {
        int result = helper(nums) - 1;
        if (result < 0) {
            result = mod - 1;
        }
        return result;
    }
    
    long long helper(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 1;
        }
        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        long long result = (helper(left) * helper(right) % mod) * c(nums.size() - 1, min(left.size(), right.size()));
        return result % mod;
    }
    
    int c(int n,int k) {
        if (cdp[n][k] != 0) {
            return cdp[n][k];
        }
        if (n == k|| k == 0) {
            return 1;
        } else {
            cdp[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % mod;
            return cdp[n][k];
        }
    }
};