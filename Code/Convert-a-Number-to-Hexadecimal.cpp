class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string h[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
        string result = "";
        int mask = 15;
        for (int i = 0; i < 32; i += 4) {
            int group = ((num >> (28 -i)) & mask);
            if (result.length() != 0 || group != 0) {
                result += h[group];
            }
        }
        if (result.length() == 0) {
            return "0";
        }
        return result;
    }
    // 不能把mask左移到最左边算，会溢出
};