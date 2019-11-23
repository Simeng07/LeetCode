class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> js;
        for (auto c : J) {
            js.insert(c);
        }
        int result = 0;
        for (auto s : S) {
            if (js.find(s) != js.end()) {
                result++;
            }
        }
        return result;
    }
};