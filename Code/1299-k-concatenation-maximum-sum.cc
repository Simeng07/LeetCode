class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long size = arr.size();
        long long result = 0;
        long long resultOnce = 0;
        long long current = 0;
        long long whole = 0;
        long long wholeMax = 0;
        long long wholeMin = 0;
        for (long long i = 0; i < size * 2; i++) {
            long long total = current + arr[i % size];
            if (total <= 0) {
                current = 0;
            } else {
                result = max(result, total);
                current = total;
            }
            if (i < size) {
                whole += arr[i % size];
                wholeMax = max(wholeMax, whole);
                wholeMin = min(wholeMin, whole);
                resultOnce = result;
            } else {
                if (k == 1) {
                    break;
                }
            }
        }
        if (k == 1) {
            return resultOnce;
        }
        result = max(result, whole * (k - 2) + wholeMax + whole - wholeMin);
        return result % 1000000007;
    }
};