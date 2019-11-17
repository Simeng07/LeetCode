class Solution {
    int result = 0;
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v1, v2;
        for (auto num : nums) {
            if (num > 0) {
                result += num;
                if (num % 3 == 1) {
                    v1.push_back(num);
                }
                if (num % 3 == 2) {
                    v2.push_back(num);
                }
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (result % 3 ==1 ) {
            int min1 = -1, min2 = -1;
            if (v1.size() > 0) {
                min1 = v1[0];
            }
            if (v2.size() > 1) {
                min2 = v2[0] + v2[1];
            }
            if (min1 > 0 && min2 > 0) {
                result -= min(min1, min2);
            } else if (min1 > 0) {
                result -= min1;
            } else if (min2 > 0) {
                result -= min2;
            }
            return result;
        }
        if (result % 3 == 2) {
            int min1 = -1, min2 = -1;
            if (v2.size() > 0) {
                min1 = v2[0];
            }
            if (v1.size() > 1) {
                min2 = v1[0] + v1[1];
            }
            if (min1 > 0 && min2 > 0) {
                result -= min(min1, min2);
            } else if (min1 > 0) {
                result -= min1;
            } else if (min2 > 0) {
                result -= min2;
            }
            return result;
        }
        return result;
    }
};