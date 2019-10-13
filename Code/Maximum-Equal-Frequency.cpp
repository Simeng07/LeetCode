class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int result = 2;
        int count[100001] = {0};
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // cout << "     " << i << " " << num << endl;
            count[num]++;
            if (count[num] != 1) {
                m[count[num] - 1]--;
                // cout << "a " << count[num] - 1 << " " << m[count[num] - 1] << endl;
                if (m[count[num] - 1] == 0) {
                    m.erase(count[num] - 1);
                    // cout << "erase " << count[num] - 1 << endl;
                }
            }
            m[count[num]]++;
            // cout << "b " << count[num] << " " << m[count[num]] << endl;
            if (m.size() == 2) {
                int a = m.begin()->first;
                int b = (++m.begin())->first;
                // cout << "2个 " << a << " " << m[a] << " " << b << " " << m[b] << endl;
                if ((a == 1 && m[a] == 1) || (b == 1 && m[b] == 1) || (abs(a - b) == 1 && m[max(a, b)] == 1)) {
                    result = i + 1;
                }
            }
        }
        if (m.size() == 1 && (m.begin()->second == 1 || m.begin()->first == 1)) {
            result = nums.size();
        }
        return result;
    }
};