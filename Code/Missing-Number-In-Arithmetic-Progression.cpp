class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int gap1 = arr[1] - arr[0];
        int gap2 = arr[2] - arr[1];
        int gap = min(abs(gap1), abs(gap2));
        if (gap1 < 0) {
            gap = -gap;
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != gap) {
                return (arr[i] + arr[i - 1]) / 2;
            }
        }
        return 0;
    }
};