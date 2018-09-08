class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        if (num > 8) {
            return result;
        }
        unordered_map<int, vector<string> > hour({
            {0, vector<string>({"0:"})}, 
            {1, vector<string>({"1:", "2:", "4:", "8:"})},
            {2, vector<string>({"3:", "5:", "6:", "9:", "10:"})},
            {3, vector<string>({"7:", "11:"})}
        });
        unordered_map<int, vector<string> > min({
            {0, vector<string>({"00"})},
            {1, vector<string>({"01", "02", "04", "08", "16", "32"})},
            {2, vector<string>({"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"})},
            {3, vector<string>({"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"})},
            {4, vector<string>({"58", "57", "54", "53", "51", "46", "45", "43", "39", "30", "29", "27", "23", "15"})},
            {5, vector<string>({"31", "47", "55", "59"})}
        });
        for (int i = 0; i <= num && i <= 3; i++) {
            if (min.find(num - i) != min.end()) {
                for (int j = 0; j < hour[i].size(); j++) {
                    for (int k = 0; k < min[num - i].size(); k++) {
                        result.push_back(hour[i][j] + min[num - i][k]);
                    }
                }
            }
        }
        return result;
    }
};