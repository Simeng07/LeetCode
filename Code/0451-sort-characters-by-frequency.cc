class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charToCount; // 可以用 int[256]
        for (auto &c : s) {
            charToCount[c]++;
        }
        
        map<int, string, greater<int>> countToChar;
        for (auto &c : charToCount) {
            countToChar[c.second] += c.first;
        }
        
        string result = "";
        for (auto &count : countToChar) {
            for (auto &c : count.second) {
                result += string(count.first, c);
            }
        }
        
        return result;
    }
};