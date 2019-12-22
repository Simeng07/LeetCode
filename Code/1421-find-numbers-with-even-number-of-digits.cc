class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            int count = 0;
            for (int i = 1; i <= 1000000; i *= 10) {
                if (num < i) {
                    if (count % 2 == 0) {
                        result++;
                    }
                    break;
                } else {
                    count++;
                }
            }
        }
        return result;
    }
};