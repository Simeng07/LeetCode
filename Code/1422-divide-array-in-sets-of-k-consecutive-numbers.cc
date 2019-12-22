class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();
        if (size % k != 0) {
            return false;
        }
        multiset<int> s(nums.begin(), nums.end());
        while (s.size() > 0) {
            int begin = *(s.begin());
            s.erase(s.begin());
            for (int i = 1; i < k; i++) {
                begin++;
                auto it2 = s.find(begin);
                if (it2 == s.end()) {
                    return false;
                }
                s.erase(it2);
            }
        }
        return true;
    }
};