class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 1;
        for (auto &quantity : quantities) {
            high = max(high, quantity);
        }
        int middle;
        while (low < high - 1) {
            middle = (low + high) / 2;
            int count = 0;
            for (auto &quantity : quantities) {
                count += ceil((double)quantity / middle);
            }
            if (count > n) {
                low = middle;
            } else {
                high = middle;
            }
        }
        int lastCount = 0;
        for (auto &quantity : quantities) {
            lastCount += ceil((double)quantity / low);
        }
        if (lastCount > n) {
            return high;
        } else {
            return low;
        }
    }
};