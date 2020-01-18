class Solution {
public:
    int minimumDistance(string word) {
        int size = word.size();
        int positionCount = 26;
        int maxDistance = 2691; // 299 * 9
        int dp[positionCount][positionCount][size];
        
        for (int i = 0; i < positionCount; i++) {
            for (int j = 0; j < positionCount; j++) {
                for (int k = 0; k < size; k++) {
                    dp[i][j][k] = maxDistance;
                }
            }
        }
        
        for (int i = 0; i < positionCount; i++) {
            dp[word[0] - 'A'][i][0] = 0; // user left hand for the first char
            dp[i][word[0] - 'A'][0] = 0; // user right hand for the first char
        }
        
        for (int k = 1; k < size; k++) {
            int lastChar = word[k - 1] - 'A';
            for (int i = 0; i < positionCount; i++) {
                for (int j = 0; j < positionCount; j++) {
                    if (i == lastChar || j == lastChar) {
                        // make sure to only calculate for possible former positions
                        dp[i][word[k] - 'A'][k] = min(dp[i][word[k] - 'A'][k], dp[i][j][k - 1] + distance(j, word[k] - 'A'));
                        dp[word[k] - 'A'][j][k] = min(dp[word[k] - 'A'][j][k], dp[i][j][k - 1] + distance(i, word[k] - 'A'));
                    }
                }
            }
        }
        
        int result = maxDistance;
        for (int i = 0; i < positionCount; i++) {
            for (int j = 0; j < positionCount; j++) {
                int lastChar = word[size - 1] - 'A';
                if (i == lastChar || j == lastChar) {
                    result = min(result, dp[i][j][size - 1]);
                }
            }
        }
        
        return result;
    }
    
    int distance(int a, int b) {
        return abs(a % 6 - b % 6) + abs(a / 6 - b / 6);
    }
};