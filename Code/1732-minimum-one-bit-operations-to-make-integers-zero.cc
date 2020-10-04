class Solution {
    // gray code
public:
    int minimumOneBitOperations(int n) {
        int leftMost = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                leftMost = i;
            }
        }
        
        int result = 0;
        bool flip = false;
        for (int i = leftMost; i >= 0; i--) {
            bool current = ((n & (1 << i)) != 0);
            if ((flip && !current) || (!flip && current)) {
                result += (1 << i);
            }
            if (current) {
                flip = !flip;
            }
        }
        
        return result;
    }
};