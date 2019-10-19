class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) return result;
        for (int i = 0; i < n; i++) {
            // the left most bit
            int mask = 1 << i;
            int s = result.size();
            while (s) {
                int num = mask | result[--s];
                result.push_back(num);
            }
        }
        return result;
    }
};