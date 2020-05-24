class Solution {
public:
    int countTriplets(vector<int>& A) {
        int count[1 << 16] = {0};
        int result = 0;
        for (auto a : A) {
            for (auto b : A) {
                count[a & b]++;
            }
        }
        for (auto a : A) {
            for (int i = 0; i < (1 << 16); i++) {
                if ((i & a) == 0) {
                    result += count[i];
                }
            }
        }
        return result;
    }
};