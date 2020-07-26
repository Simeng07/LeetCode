class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = target[0];
        for (int i = 1; i < target.size(); i++) {
            result += (target[i] > target[i - 1] ? target[i] - target[i - 1] : 0);
        }
        return result;
    }
};