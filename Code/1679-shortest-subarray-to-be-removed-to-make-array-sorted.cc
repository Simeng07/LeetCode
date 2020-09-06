class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() == 1) {
            return 0;
        }
        int n = arr.size();
        int l = 1;
        for (; l < n; l++) {
            if (arr[l] < arr[l - 1]) {
                break;
            }
        }
        // already non-decreasing
        if (l == n) {
            return 0;
        }
        int r = 1;
        for (; r < n; r++) {
            if (arr[n - r - 1] > arr[n - r]) {
                break;
            }
        }
        
        int result = min(n - l, n - r);
        
        // cut out the middle part
        int i = 0;
        for (; i < l; i++) {
            if (arr[i] > arr[n - r]) {
                result = min(result, n - (r + i));
                break;
            }
        }
        if (i == l) {
            result = n - (r + l);
            return result;
        }
        
        i = 0;
        for (; i < r; i++) {
            if (arr[n - i - 1] < arr[l - 1]) {
                result = min(result, n - (l + i));
                break;
            }
        }
        if (i == r) {
            result = n - (r + l);
        }
        return result;
    }
};