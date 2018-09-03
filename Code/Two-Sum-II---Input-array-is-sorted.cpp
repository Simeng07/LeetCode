class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0, q = numbers.size() - 1;
        while (true) {
            if (numbers[p] + numbers[q] == target) {
                return {p + 1, q + 1};
            }
            if (numbers[p] + numbers[q] < target) {
                p++;
            } else {
                q--;
            }
        }
    }
};