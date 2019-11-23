class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 对的
        // sort(nums.begin(), nums.end());
        // vector<int> result;
        // int p = 1;
        // int q = 0;
        // int n = nums.size();
        // while (p <= n && q < n) {
        //     if (nums[q] > p) {
        //         result.push_back(p);
        //         p++;
        //     } else if (nums[q] < p){
        //         q++;
        //     } else {
        //         p++;
        //         q++;
        //     }
        // }
        // while (p <= n) {
        //     result.push_back(p);
        //     p++;
        // }
        // return result;
        
        // 有的数字对应的index标记为负数，是原来那个数字的负数
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int posNum = (nums[i] > 0 ? nums[i] : -nums[i]) - 1;
            nums[posNum] = nums[posNum] > 0 ? -nums[posNum] : nums[posNum];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};