class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1}, 
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2}, 
            {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3},
            {'Q', 1}, {'W', 1}, {'E', 1}, {'R', 1}, {'T', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1}, {'P', 1}, 
            {'A', 2}, {'S', 2}, {'D', 2}, {'F', 2}, {'G', 2}, {'H', 2}, {'J', 2}, {'K', 2}, {'L', 2}, 
            {'Z', 3}, {'X', 3}, {'C', 3}, {'V', 3}, {'B', 3}, {'N', 3}, {'M', 3}
        };
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (word.size() == 0) {
                continue;
            }
            int a = m[word[0]];
            bool can = true;
            for (int j = 1; j < word.size(); j++) {
                if (m[word[j]] != a) {
                    can = false;
                    break;
                }
            }
            if (can) {
                result.push_back(word);
            }
        }
        return result;
    }
    // 不要求考虑shift更简单了，就不算大小写了，意义不大，直接定义好
};