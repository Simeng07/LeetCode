class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int mask = 1;
            int counta = 0, countb = 0;
            while (mask <= a || mask <= b) {
                if (mask & a) {
                    counta++;
                }
                if (mask & b) {
                    countb++;
                }
                mask <<= 1;
            }
            if (counta == countb) {
                return a < b;
            }
            return counta < countb;
        });
        return arr;
    }
};