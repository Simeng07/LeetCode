class Solution {
public:
    vector<int> closestDivisors(int num) {
        int left = sqrt(num + 2);
        while (left > 1) {
            if ((num + 1) % left == 0) {
                return {left, (num + 1) / left};
            }
            if ((num + 2) % left == 0) {
                return {left, (num + 2) / left};
            }
            left--;
        }
        return {1, num + 1};
    }
};