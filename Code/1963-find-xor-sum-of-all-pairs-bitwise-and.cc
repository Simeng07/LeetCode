class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        for (auto i : arr1) {
            a ^= i;
        }
        for (auto i : arr2) {
            b ^= i;
        }
        return (a & b);
    }
};