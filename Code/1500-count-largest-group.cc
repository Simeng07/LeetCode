class Solution {
public:
    int countLargestGroup(int n) {
        int count[10001] = {0};
        for (int i = 1; i <= n; i++) {
            int sum = countSum(i);
            count[sum]++;
        }
        int size = 0;
        int result = 0;
        for (int i = 10000; i >= 0; i--) {
            if (count[i] > size) {
                result = 1;
                size = count[i];
            } else if (count[i] == size) {
                result++;
            }
        }
        return result;
    }
    int countSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
};