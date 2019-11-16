class Solution {
    long long v[1001] = {0};
public:
    int numberOfWays(int num_people) {
        v[0] = 1;
        v[2] = 1;
        v[4] = 2;
        v[6] = 5;
        v[8] = 14;
        for (int i = 10; i <= num_people; i += 2) {
            for (int j = 0; j <= (i - 2) / 2; j += 2) {
                v[i] += (v[j] * v[i - j - 2]) * ((j == i - j - 2) ? 1 : 2);
                v[i] %= 1000000007;
            }
            // cout << i << " " << v[i] << endl;
        }
        return v[num_people];
    }
};