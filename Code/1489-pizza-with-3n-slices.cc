class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int count = slices.size();
        int dp[500][500] = {0};
        int chooseFirst, notChooseFirst;
        
        // choose the first one
        dp[0][1] = slices[0];
        dp[1][1] = slices[0];
        for (int i = 2; i < count; i++) {
            for (int j = 1; j <= min(count / 3, i); j++) {
                if (i == count - 1) {
                    dp[i][j] = dp[i - 1][j]; // not choose the last one
                } else {
                    dp[i][j] = max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);
                }
            }
        }
        chooseFirst = dp[count - 1][count / 3];
        
        // not choose the first one
        memset(dp, 0, sizeof(int) * 500 * 500);
        dp[1][1] = slices[1];
        for (int i = 2; i < count; i++) {
            for (int j = 1; j <= min(count / 3, i); j++) {
                dp[i][j] = max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);
            }
        }
        notChooseFirst = dp[count - 1][count / 3];
        
        return max(chooseFirst, notChooseFirst);
    }
};


// TLE:
// class Solution {
//     vector<pair<int, int>> v;
//     unordered_set<int> s;
//     int count;
//     int result = 0;
// public:
//     int maxSizeSlices(vector<int>& slices) {
//         count = slices.size() / 3;
//         for (int i = 0; i < slices.size(); i++) {
//             v.push_back({slices[i], i});
//         }
//         sort(v.begin(), v.end(), greater<pair<int, int>>());
//         helper(0, 0, 0);
//         return result;
//     }
    
//     void helper(int index, int currentCount, int currentSize) {
//         if (currentCount == count) {
//             result = max(currentSize, result);
//             return;
//         }
//         if (index >= count * 3) {
//             return;
//         }
//         if (currentSize + v[index].first * (count - currentCount) <= result) {
//             return;
//         }
//         if (s.find(v[index].second) != s.end()) {
//             helper(index + 1, currentCount, currentSize);
//             return;
//         }
        
//         // pick
//         int left = v[index].second - 1;
//         if (left < 0) {
//             left = count * 3 - 1;
//         }
//         int right = v[index].second + 1;
//         if (right >= count * 3) {
//             right = 0;
//         }
//         bool hasLeft = (s.find(left) != s.end());
//         bool hasRight = (s.find(right) != s.end());
//         s.insert(left);
//         s.insert(right);
//         s.insert(v[index].second);
//         helper(index + 1, currentCount + 1, currentSize + v[index].first);
//         if (!hasLeft) {
//             s.erase(left);
//         }
//         if (!hasRight) {
//             s.erase(right);
//         }
//         s.erase(v[index].second);
        
//         // not pick
//         helper(index + 1, currentCount, currentSize);
//     }
// };