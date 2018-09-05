class Solution {
public:
    int addDigits(int num) {
        int tmp = 0;
        while (num > 9) {
            while (num > 0) {
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
            tmp = 0;
        }
        return num;
        
        // return ((num-1) % 9) + 1; ???
    }
};