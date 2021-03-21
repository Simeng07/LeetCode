class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        long long middle = (low + high) / 2;
        long long total = sum(n, index, middle);
        while (low < middle) {
            total = sum(n, index, middle);
            // cout << low << " " << middle << " " << high << " " << total << endl;
            if (total == maxSum) {
                return middle;
            }
            if (total > maxSum) {
                high = middle;
            } else {
                low = middle;
            }
            middle = (low + high) / 2;
        }
        if (sum(n, index, high) <= maxSum) {
            return high;
        }
        if (sum(n, index, middle) <= maxSum) {
            return middle;
        }
        return low;
    }
    
    long long sum(int n, int index, int current) {
        long long left, right;
        if (index < current) {
            left = ((long long)(current - index + current)) * (index + 1) / 2;
            // cout << "left a " << left << endl;
        } else {
            left = ((long long)(1 + current)) * current / 2 + (index - current + 1);
            // cout << "left b " << left << endl;
        }
        if (index + current <= n) {
            right = ((long long)(1 + current)) * current / 2 + (n - current - index);
            // cout << "right a " << right << endl;
        } else {
            right = ((long long)(current - (n - index - 1) + current)) * (n - index) / 2;
            // cout << "right b " << right << endl;
        }
        return left + right - current;
    }
};