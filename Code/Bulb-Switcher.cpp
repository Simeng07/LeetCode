class Solution {
public:
    int bulbSwitch(int n) {
        // 因子个数与某一个灯泡亮暗相关
        // 只有完全平方数有奇数个因子
        int result = 0;
        for (int i = 1; i <= n / i; i++) {
            result++;
        }
        return result;
    }
};