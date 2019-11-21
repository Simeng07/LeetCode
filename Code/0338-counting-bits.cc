class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if (num == 0) return result;
        int base = 0;
        while (true) {
            for (int j = 0; j < (1 << base); j++) {
                result.push_back(result[j] + 1);
                if (result.size() == num + 1) return result;
            }
            base++;
        }
        return result;
    }
};