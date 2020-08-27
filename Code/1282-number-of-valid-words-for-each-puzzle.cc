class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> m;
        for (auto &word : words) {
            int num = 0;
            for (auto &c : word) {
                num |= (1 << (c - 'a'));
            }
            m[num]++;
        }
        vector<int> result;
        for (auto &puzzle : puzzles) {
            int count = 0;
            for (int i = 0; i < (1 << puzzle.length() - 1); i++) {
                int mask = (1 << (puzzle[0] - 'a'));
                for (int j = 0; j < puzzle.length() - 1; j++) {
                    if (i & (1 << j)) {
                        mask |= (1 << (puzzle[j + 1] - 'a'));
                    }
                }
                count += m[mask];
            }
            result.push_back(count);
        }
        return result;
    }
    // 超时了：
    // vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    //     vector<int> wordNum(words.size(), 0);
    //     for (int i = 0; i < words.size(); i++) {
    //         for (auto &c : words[i]) {
    //             wordNum[i] |= (1 << (c - 'a'));
    //         }
    //     }
    //     vector<int> result(puzzles.size(), 0);
    //     for (int i = 0; i < puzzles.size(); i++) {
    //         int num = 0;
    //         for (auto &c : puzzles[i]) {
    //             num |= (1 << (c - 'a'));
    //         }
    //         int count = 0;
    //         for (auto n : wordNum) {
    //             if (n & (1 << (puzzles[i][0] - 'a'))) {
    //                 if ((n & num) == n) {
    //                     count++;
    //                 }
    //             }
    //         }
    //         result[i] = count;
    //     }
    //     return result;
    // }
};