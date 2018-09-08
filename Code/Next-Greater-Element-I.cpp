class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < findNums.size(); i++) {
            auto it = find(nums.begin(), nums.end(), findNums[i]);
            if (it != nums.end()) {
                bool has = false;
                while (it != nums.end()) {
                    if (*it > findNums[i]) {
                        has = true;
                        result.push_back(*it);
                        break;
                    }
                    it++;
                }
                if (!has) {
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};