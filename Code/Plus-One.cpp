class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int a[n + 1] = {0};
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            a[i + 1] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        vector<int> result;
        if (carry > 0) {
            result.push_back(carry);
        }
        for (int i = 1; i < n + 1; i++) {
            result.push_back(a[i]);
        }
        return result;
    }
};