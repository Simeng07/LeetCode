class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> m;
        for (auto &rec : rectangles) {
            m[((double)rec[0]) / rec[1]]++;
        }
        long long result = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            long long n = it->second;
            if (n != 0) {
                result += n * (n - 1) / 2;
            }
        }
        return result;
    }
};