class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = arr.size();
        int should = count / 4;
        if (count % 4 != 0) {
            should++;
        }
        int current = arr[0];
        int currentCount = 0;
        for (int i = 1; i < count; i++) {
            if (arr[i] == current) {
                currentCount++;
                if (currentCount == should) {
                    return current;
                }
            } else {
                current = arr[i];
                currentCount = 0;
            }
        }
        return current;
    }
};