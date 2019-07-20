class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorn = 0;
        for (auto num : nums) {
            xorn ^= num;
        }
        
        int lowest = 1;
        while ((xorn & lowest) == 0) {
            lowest <<= 1;
        }
        
        int num1 = 0, num2 = 0;
        for (auto num : nums) {
            if (num & lowest) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};