class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result = 0;
        long long count[1024] = {0};
        count[0] = 1;
        int current = 0;
        for (int i = 0; i < word.size(); i++) {
            int index = (1 << (word[i] - 'a'));
            current ^= index;
            result += count[current];
            count[current]++;
            for (int i = 0; i < 10; i++) {
                result += count[current ^ (1 << i)];
            }
        }
        return result;
    }
};