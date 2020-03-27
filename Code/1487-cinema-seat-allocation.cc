class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> m;
        for (auto &seat : reservedSeats) {
            if (seat[1] > 1 && seat[1] < 10) {
                m[seat[0]] |= (1 << (seat[1] - 2));
            }
        }
        int result = n * 2;
        for (auto row : m) {
            bool left = !(row.second & 0b11110000);
            bool middle = !(row.second & 0b00111100);
            bool right = !(row.second & 0b00001111);
            if (left && right) {
                continue;
            } else if (left || right || middle) {
                result -= 1;
            } else {
                result -= 2;
            }
        }
        return result;
    }
};