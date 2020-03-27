class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            int sum = 0;
            int count = 0;
            int root = sqrt(num);
            if (root * root == num) {
                continue;
            }
            for (int i = 1; i <= root; i++) {
                if (num % i == 0) {
                    sum += (i + num / i);
                    count += 2;
                }
            }
            if (count == 4) {
                result += sum;
            }
        }
        return result;
    }
};