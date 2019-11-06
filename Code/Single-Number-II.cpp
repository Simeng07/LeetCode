class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int mask = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (i == 0) {
                mask = 1;
            } else {
                mask <<= 1;
            }
            int count = 0;
            for (auto num : nums) {
                if (mask & num) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                result |= mask;
            }
        }
        return result;
    }
};