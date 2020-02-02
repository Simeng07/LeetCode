class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int size = arr.size();
        vector<vector<int>> v(size, vector<int>(2));
        for (int i = 0; i < size; i++) {
            v[i] = {arr[i], i};
        }
        sort(v.begin(), v.end());
        int dp[size];
        for (int i = 0; i < size; i++) {
            int currentIndex = v[i][1];
            dp[currentIndex] = 1;
            int right = 0;
            for (int j = 1; j <= d && currentIndex + j < size; j++) {
                if (arr[currentIndex + j] >= arr[currentIndex]) {
                    break;
                } else {
                    right = max(right, dp[currentIndex + j]);
                }
            }
            int left = 0;
            for (int j = 1; j <= d && currentIndex - j >= 0; j++) {
                if (arr[currentIndex - j] >= arr[currentIndex]) {
                    break;
                } else {
                    left = max(left, dp[currentIndex - j]);
                }
            }
            dp[currentIndex] = 1 + max(right, left);
        }
        int result = 1;
        for (int i = 0; i < size; i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};