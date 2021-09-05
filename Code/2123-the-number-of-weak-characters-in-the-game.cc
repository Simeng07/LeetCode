class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        int n = properties.size();
        int currentx = INT_MAX;
        int maxNum = 0, tmpMaxNum = 0;
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (properties[i][0] != currentx) {
                maxNum = max(maxNum, tmpMaxNum);
                tmpMaxNum = 0;
                currentx = properties[i][0];
            }
            if (properties[i][1] < maxNum) {
                result++;
            }
            tmpMaxNum = max(tmpMaxNum, properties[i][1]);
        }
        return result;
    }
};