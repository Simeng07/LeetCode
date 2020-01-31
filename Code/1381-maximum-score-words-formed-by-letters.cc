class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int size = words.size();
        int maxNum = pow(2, size);
        int result = 0;
        int letterAry[26] = {0};
        unordered_map<char, priority_queue<int>> m;
        for (auto letter : letters) {
            letterAry[letter - 'a']++;
        }
        for (int i = 1; i <= maxNum; i++) {
            // cout << "--------\ni = " << i << endl;
            int tmp[26];
            memcpy(tmp, letterAry, 26 * sizeof(int));
            int mask = 1, tmpScore = 0;
            bool valid = true;
            for (int j = 0; j < words.size() && valid; j++) {
                if ((mask << j) & i) {
                    for (auto c : words[j]) {
                        tmp[c - 'a']--;
                        if (tmp[c - 'a'] < 0) {
                            // cout << "invalid: " << c << " " << tmp[c - 'a'] << endl;
                            valid = false;
                            break;
                        }
                        tmpScore += score[c - 'a'];
                    }
                }
            }
            if (valid) {
                result = max(result, tmpScore);
            }
        }
        return result;
    }
};