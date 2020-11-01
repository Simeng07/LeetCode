class Solution {
    int dp[1001][1001];
    int charCount[1001][26];
    int wordLength;
    int MOD = 1000000007;
public:
    int numWays(vector<string>& words, string target) {
        for (auto &word : words) {
            for (int i = 0; i < word.size(); i++) {
                charCount[i][word[i] - 'a']++;
            }
        }
        wordLength = words[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(target, 0, 0);
    }
    
    int helper(string &target, int wordIndex, int targetIndex) {
        if (targetIndex == target.size()) {
            return 1;
        }
        if (wordIndex >= wordLength) {
            return 0;
        }
        if (dp[targetIndex][wordIndex] >= 0) {
            return dp[targetIndex][wordIndex];
        }
        int c = target[targetIndex];
        long long result = (long long)charCount[wordIndex][c - 'a'] * helper(target, wordIndex + 1, targetIndex + 1);
        result += helper(target, wordIndex + 1, targetIndex);
        result %= MOD;
        dp[targetIndex][wordIndex] = result;
        return result;
    }
};