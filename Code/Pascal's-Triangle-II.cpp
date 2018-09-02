class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        for (int i = 0; i < rowIndex; i++) {
            result.push_back(1);
            for (int j = i; j > 0; j--) {
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};