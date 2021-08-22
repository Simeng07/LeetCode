class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxNum = (1 << n) - 1;
        string result = "";
        for (int i = 0; i <= maxNum; i++) {
            if (i != 0 && i != nums.size() && nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                i--;
                continue;
            }
            if (i == nums.size() || stoi(nums[i], 0, 2) != i) {
                for (int j = 0; j < n; j++) {
                    if ((i >> j) & 1) {
                        result = "1" + result;
                    } else {
                        result = "0" + result;
                    }
                }
                break;
            }
        }
        return result;
    }
};