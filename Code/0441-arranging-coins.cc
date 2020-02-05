class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }
        
        int low = 0, high = n;
        while (low < high) {
            long long mid = (high + low) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum == n) {
                return mid;
            } else if (sum < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }
};