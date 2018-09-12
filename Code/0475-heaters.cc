class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size() == 0 || heaters.size() == 0) {
            return 0;
        }
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int nhouse = houses.size();
        int nheater = heaters.size();
        int p = 0, q = 0;
        int result = 0;
        // 把house放进heater的里面
        while (houses[p] <= heaters[0] && p < nhouse) {
            p++;
        }
        // 如果有比第一个heater还小的house，则result至少是这个间距
        if (p != 0) {
            result = heaters[0] - houses[0];
        }
        // 所有house都比heater小
        if (p == nhouse) {
            return heaters[0] - houses[0];
        }
        while (p < nhouse) {
            if (q + 1 < nheater) {
                // 取离house比较近的那个heater值来对比
                while (heaters[q] <= houses[p] && houses[p] <= heaters[q + 1]) {
                    result = max(result, min(houses[p] - heaters[q], heaters[q + 1] - houses[p]));
                    p++;
                    if (p == nhouse) {
                        return result;
                    }
                }
            } else {
                result = max(result, houses[nhouse - 1] - heaters[nheater - 1]);
                return result;
            }
            q++;
        }
        return result;
    }
};