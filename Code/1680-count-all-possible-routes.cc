class Solution {
    int dp[100][201];
    int mod = 1000000007;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        int startCity = locations[start];
        int finishCity = locations[finish];
        if (finishCity - startCity > fuel) {
            return 0;
        }
        sort(locations.begin(), locations.end());
        start = lower_bound(locations.begin(), locations.end(), startCity) - locations.begin();
        finish = lower_bound(locations.begin(), locations.end(), finishCity) - locations.begin();
        return helper(locations, start, finish, fuel) + (start == finish ? 1 : 0);
    }
    
    int helper(vector<int>& locations, int start, int finish, int fuel) {
        if (dp[start][fuel] >= 0) {
            return dp[start][fuel];
        }
        long long result = 0;
        for (int i = start + 1; i < locations.size() && locations[i] - locations[start] <= fuel; i++) {
            if (i == finish) {
                result++;
            }
            result += helper(locations, i, finish, fuel - (locations[i] - locations[start]));
            result %= mod;
        }
        for (int i = start - 1; i >= 0 && locations[start] - locations[i] <= fuel; i--) {
            if (i == finish) {
                result++;
            }
            result += helper(locations, i, finish, fuel - (locations[start] - locations[i]));
            result %= mod;
        }
        dp[start][fuel] = result;
        return result;
    }
};