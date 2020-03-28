class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int result = 0;
        int maxNum = 0;
        for (int i = 0; i < light.size(); i++) {
            maxNum = max(maxNum, light[i]);
            if (maxNum == i + 1) {
                result++;
            }
        }
        return result;
    }
};