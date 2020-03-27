class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int result = 0;
        for (auto num : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), num - d);
            if (it == arr2.end()) {
                result++;
                continue;
            }
            if (*it > num + d) {
                result++;
                continue;
            }
        }
        return result;
    }
};