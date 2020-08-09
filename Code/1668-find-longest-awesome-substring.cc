class Solution {
public:
    int longestAwesome(string s) {
        int result = 0, current = 0;
        vector<int> v(1024, s.size());
        v[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            current ^= 1 << (s[i] - '0'); // 到目前为止的所有数字奇偶
            for (int j = 0; j < 10; j++) {
                // 以j为中心的回文，即j是奇数次，其余9个数字都是偶数次
                // 例如current是011110，j是2，则要找的数字是011010
                result = max(result, i - v[current ^ (1 << j)]);
            }
            // 所有数字都是偶数次
            result = max(result, i - v[current]);
            v[current] = min(v[current], i);
        }
        return result;
    }
};