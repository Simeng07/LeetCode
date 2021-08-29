class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string &a, const string &b){
            if (a.size() < b.size()) {
                return false;
            }
            if (a.size() > b.size()) {
                return true;
            }
            return (a > b);
        });
        return nums[k - 1];
    }
};