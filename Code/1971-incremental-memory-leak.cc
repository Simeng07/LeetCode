class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        for (int i = 1; i < INT_MAX; i++) {
            if (max(memory1, memory2) < i) {
                return {i, memory1, memory2};
            }
            if (memory2 > memory1) {
                memory2 -= i;
            } else {
                memory1 -= i;
            }
        }
        return {0, 0, 0};
    }
};